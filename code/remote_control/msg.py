import socket
import time

def message_to_esp32(ip,port,message):

    UDP_IP = str(ip)   # 替换为你的ESP32-S3设备的IP地址

    UDP_PORT = int(port)    # 替换为你的ESP32-S3设备监听的端口号

    # 创建UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # 要发送的消息
    message = b"forward"  # 使用字节类型发送数据

    # 发送消息到ESP32-S3
    sock.sendto(message, (UDP_IP, UDP_PORT))

    # 时间戳记录
    time_stamp = time.asctime(time.localtime(time.time()))
    
    print( time_stamp + message + "sent")