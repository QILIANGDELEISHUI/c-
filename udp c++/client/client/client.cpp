#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

int main() {
    // 初始化WinSock
    WSADATA wsaData;
    WORD version = MAKEWORD(2, 2);
    if (WSAStartup(version, &wsaData) != 0) {
        std::cerr << "Failed to initialize WinSock" << std::endl;
        return 1;
    }

    // 创建UDP套接字
    SOCKET clientSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket" << std::endl;
        WSACleanup();
        return 1;
    }

    // 服务端地址和端口
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(12345);

    // 使用inet_pton来转换IP地址
    if (inet_pton(AF_INET, "127.0.0.1", &(serverAddress.sin_addr)) != 1) {
        std::cerr << "Failed to convert IP address" << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // 发送数据
    int data = 10;
    if (sendto(clientSocket, (char*)&data, sizeof(data), 0, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Failed to send data" << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // 关闭套接字
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}