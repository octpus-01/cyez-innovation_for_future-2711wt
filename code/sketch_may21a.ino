#include <Arduino.h>

// 摇杆引脚配置
#define JOYSTICK_X_PIN 2    // 摇杆X轴模拟输入
#define JOYSTICK_Y_PIN 3    // 摇杆Y轴模拟输入
#define JOYSTICK_BTN_PIN 4  // 摇杆按键数字输入

// 直流电机配置（保持原有）
#define MOTOR_PWM_PIN 5
#define MOTOR_IN1_PIN 6
#define MOTOR_IN2_PIN 7
const int motorChannel = 0;

// 舵机配置（保持原有）
#define SERVO_PIN 8
const int servoChannel = 1;

// 控制参数
const int DEAD_ZONE = 100;        // 摇杆死区范围
const int SERVO_MIN = -45;        // 舵机最小角度
const int SERVO_MAX = 45;         // 舵机最大角度
const int MOTOR_MAX_SPEED = 200;  // 电机最大转速（0-255）

// 全局变量存储摇杆状态
int lastServoAngle = 0;
int lastMotorSpeed = 0;

void setup() {
  Serial.begin(115200);
  
  // 初始化摇杆引脚
  pinMode(JOYSTICK_BTN_PIN, INPUT_PULLUP);
  
  // 初始化舵机PWM
  ledcSetup(servoChannel, 50, 16);  // 舵机50Hz
  ledcAttachPin(SERVO_PIN, servoChannel);
  
  // 初始化直流电机PWM
  pinMode(MOTOR_IN1_PIN, OUTPUT);
  pinMode(MOTOR_IN2_PIN, OUTPUT);
  ledcSetup(motorChannel, 5000, 8);
  ledcAttachPin(MOTOR_PWM_PIN, motorChannel);
  
  // 初始状态
  setServoAngle(0);
  motorStop();
}

void loop() {
  // 读取摇杆状态
  int xValue = analogRead(JOYSTICK_X_PIN);
  int yValue = analogRead(JOYSTICK_Y_PIN);
  bool buttonState = digitalRead(JOYSTICK_BTN_PIN);

  // 处理紧急停止按钮
  if (!buttonState) {
    emergencyStop();
    return;
  }

  // 控制舵机（X轴）
  controlServo(xValue);
  
  // 控制直流电机（Y轴）
  controlMotor(yValue);
  
  delay(20); // 控制循环周期
}

void controlServo(int rawX) {
  // 转换X轴模拟值到角度（0-4095 → -45°-45°）
  int angle = map(rawX, 0, 4095, SERVO_MIN, SERVO_MAX);
  
  // 应用死区
  if(abs(angle - lastServoAngle) > 1){ // 1度滤波
    setServoAngle(angle);
    lastServoAngle = angle;
  }
}

void controlMotor(int rawY) {
  // 转换Y轴模拟值到电机速度（0-4095 → -255-255）
  int speed = map(rawY, 0, 4095, -MOTOR_MAX_SPEED, MOTOR_MAX_SPEED);
  
  // 应用死区
  if(abs(speed) < MOTOR_MAX_SPEED*0.1){ // 10%死区
    motorStop();
    return;
  }

  // 限制速度范围
  speed = constrain(speed, -MOTOR_MAX_SPEED, MOTOR_MAX_SPEED);
  
  // 控制电机方向
  if(speed > 0){
    digitalWrite(MOTOR_IN1_PIN, HIGH);
    digitalWrite(MOTOR_IN2_PIN, LOW);
    ledcWrite(motorChannel, abs(speed));
  } else {
    digitalWrite(MOTOR_IN1_PIN, LOW);
    digitalWrite(MOTOR_IN2_PIN, HIGH);
    ledcWrite(motorChannel, abs(speed));
  }
}

void setServoAngle(int angle) {
  angle = constrain(angle, SERVO_MIN, SERVO_MAX);
  
  // 计算舵机脉宽（500-2500μs对应-90°~90°）
  float pulseWidth = 1500 + (angle * 1000.0 / 90.0);
  uint32_t duty = (pulseWidth * (1 << 16)) / (1000000.0 / 50);
  
  ledcWrite(servoChannel, duty);
}

void motorStop() {
  digitalWrite(MOTOR_IN1_PIN, LOW);
  digitalWrite(MOTOR_IN2_PIN, LOW);
  ledcWrite(motorChannel, 0);
}

void emergencyStop() {
  motorStop();
  setServoAngle(0);
  while(!digitalRead(JOYSTICK_BTN_PIN)){ // 等待按钮释放
    delay(10);
  }
}
Serial.printf("X:%-4d Y:%-4d Button:%d\n", xValue, yValue, buttonState);
