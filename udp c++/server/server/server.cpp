#include <iostream>
#include <WinSock2.h>

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
    SOCKET serverSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket" << std::endl;
        WSACleanup();
        return 1;
    }

    // 监听地址和端口
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(12345);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // 绑定地址和端口
    if (bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Failed to bind socket" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // 接收数据
    int data = 0;
    sockaddr_in clientAddress{};
    int clientAddressSize = sizeof(clientAddress);
    if (recvfrom(serverSocket, (char*)&data, sizeof(data), 0, (sockaddr*)&clientAddress, &clientAddressSize) == SOCKET_ERROR) {
        std::cerr << "Failed to receive data" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // 打印接收到的数据
    std::cout << "Received data: " << data << std::endl;

    // 关闭套接字
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}