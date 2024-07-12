//
// Created by Flowey on 6/07/2024.
//

#include "ServerSocket.h"
#include <iostream>


ServerSocket::ServerSocket(CommonSock::SocketInfo server_info, u_long ip, CommonSock::ListenSocketInfo listen) :
    SocketBase(server_info, ip)
{
    // auto [domain, type, protocol, port] = server;

    this->connection = ServerSocket::EstablishConnection(this->sock, this->address, listen);
    CheckConnection(this->connection);
}


int ServerSocket::EstablishConnection(int sock, sockaddr_in address, CommonSock::ListenSocketInfo listen_info)
{
    std::cout << "Establishing connection" << std::endl;
    auto [should_listen, backlog] = listen_info;
    socklen_t len = sizeof(address);
    
    if (bind(sock, reinterpret_cast<sockaddr *>(&address), len) == SOCKET_ERROR)
    {
        std::cerr << "Bind failed: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    if (should_listen)
    {
        if (listen(sock, SOMAXCONN) == SOCKET_ERROR)
        {
            std::cerr << "Listen failed: " << WSAGetLastError() << std::endl;
            closesocket(sock);
            WSACleanup();
            return 1;
        }
    }
}
