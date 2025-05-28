// 这是我们开发程序的v2 基于esp32-s3 
// ESP32-S3 WiFi遥控小船船体部分开发板代码
// 作者: Lingma
// 日期: [当前日期]

#include <WiFi.h>
#include <WiFiUdp.h>

// WiFi配置
const char* ssid = "YourWiFiSSID";          // 替换为您的WiFi名称
const char* password = "YourWiFiPassword";  // 替换为您的WiFi密码

// UDP配置
const int localPort = 8888;                // 本地端口
const int remotePort = 8888;               // 远程端口
const char* remoteIP = "192.168.1.100";    // 远程IP地址，替换为您的控制设备IP

// 初始化WiFi和UDP
WiFiUDP udp;
char packetBuffer[255];                    // 缓冲区用于存储接收到的数据

void setup() {
  Serial.begin(115200);                    // 初始化串口通信
  WiFi.begin(ssid, password);              // 连接到WiFi网络
  while (WiFi.status() != WL_CONNECTED) {  // 等待连接成功
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  udp.begin(localPort);                    // 开始UDP监听
  Serial.print("UDP listening on port: ");
  Serial.println(localPort);
}

void loop() {
  int packetSize = udp.parsePacket();      // 检查是否有数据包到达
  if (packetSize) {
    Serial.print("Received packet of size: ");
    Serial.println(packetSize);
    
    // 读取数据包
    int len = udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;               // 添加字符串结束符
    }
    Serial.println("Contents:");
    Serial.println(packetBuffer);

    // 处理接收到的命令
    processCommand(packetBuffer);
  }
}

void processCommand(const char* command) {
  // 根据接收到的命令执行相应的操作
  // 例如：前进、后退、左转、右转等
  // 这里仅作示例，具体实现需要根据您的硬件和控制逻辑来编写
  if (strcmp(command, "forward") == 0) {
    Serial.println("Moving forward");
    // 在这里添加前进的代码
    
  } else if (strcmp(command, "backward") == 0) {
    Serial.println("Moving backward");
    // 在这里添加后退的代码
  } else if (strcmp(command, "left") == 0) {
    Serial.println("Turning left");
    // 在这里添加左转的代码
  } else if (strcmp(command, "right") == 0) {
    Serial.println("Turning right");
    // 在这里添加右转的代码
  } else {
    Serial.println("Unknown command");
  }
}