//
// Created by Flowey on 8/07/2024.
//

#include "server.h"

#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


ServerBase::ServerBase(/*ServerDefinition::*/SocketInfo server_info, /*ServerDefinition::*/ListenSocketInfo listen_info)
{
    result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0)
    {
        std::cerr << "WSAStartup failed: " << WSAGetLastError() << std::endl;
        exit(1);
    }
    
    server_socket = new ServerSocket(server_info, INADDR_ANY, listen_info);
    // Run();
}

void ServerBase::Run()
{
        std::cout << "Server Running... Waiting for new connection..." << std::endl;
        // printf("Server Running...\n");
        // printf("Server Running... Waiting for new connection...\n");
    while (true)
    {

        Acceptor();
        Handler();
        // Responder();

        std::cout << "Server Stopped" << std::endl;
        // printf("Server stopped\n");
        // Stop();
    }
    
}


void ServerBase::Acceptor()
{
    // TODO: implement INVALID_SOCKET logik

    
    /*sockaddr_in address = server_socket->GetAddress();
    connection_socket = accept(
        server_socket->GetSock(),
        reinterpret_cast<sockaddr*>(&address),
        reinterpret_cast<socklen_t*>(&address.sin_addr.s_addr)
        );

    if (connection_socket == INVALID_SOCKET)
    {
        std::cerr << "accept failed: " << WSAGetLastError() << std::endl;
        closesocket(server_socket->GetSock());
        return;
        // WSACleanup();
        // exit(EXIT_FAILURE);
    }

    memset(recvbuf, 0, sizeof(recvbuf)); // Clear the buffer
    int bytes_received = recv(connection_socket, recvbuf, sizeof(recvbuf) - 1, 0);
    if (bytes_received == SOCKET_ERROR)
    {
        std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
        closesocket(connection_socket);
        connection_socket = INVALID_SOCKET;
        return;
    }

    recvbuf[bytes_received] = '\0';*/

    std::cout << "Server Accepting...\n" << std::endl;

    // printf("Server Accepting...\n");
    sockaddr_in clientAddress;
    int clientAddressLen = sizeof(clientAddress);
    SOCKET clientSocket = accept(server_socket->GetSock(), (sockaddr*)&clientAddress, &clientAddressLen);
    if (clientSocket == INVALID_SOCKET)
    {
        std::cerr << "Accept failed: " << WSAGetLastError() << std::endl;
        closesocket(server_socket->GetSock());
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    std::cout << "Connection accepted from " << inet_ntoa(clientAddress.sin_addr) << ":" << ntohs(
        clientAddress.sin_port) << std::endl;
    connection_socket = clientSocket;
}

void ServerBase::Handler()
{
    // if (connection_socket != INVALID_SOCKET)
    // {
    //     std::cout << "Received message: " << recvbuf << std::endl;
    // }
    // else
    // {
    //     std::cerr << "Handler called without a valid connection socket." << std::endl;
    // }
    printf("Server handling...\n");

    char recvBuffer[4096];
    int bytesReceived = recv(connection_socket, recvBuffer, sizeof(recvBuffer) - 1, 0);
    if (bytesReceived > 0)
    {
        recvBuffer[bytesReceived] = '\0'; // Null-terminate the received data
        std::cout << "Received request:\n" << recvBuffer << std::endl;

        // Prepare an HTTP response
        const char* httpResponse =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: 43\r\n"
            "\r\n"
            "<html><body>Hello from the server!</body></html>";

        // Send the HTTP response
        send(connection_socket, httpResponse, strlen(httpResponse), 0);
    }
    else
    {
        std::cerr << "Recv failed or connection closed: " << WSAGetLastError() << std::endl;
    }
    closesocket(connection_socket);
}

void ServerBase::Responder()
{
    /*if (connection_socket != INVALID_SOCKET)
    {
        int byte_sent = send(connection_socket, hello, sizeof(hello), MSG_WAITALL);
        if (byte_sent == SOCKET_ERROR)
        {
            std::cerr << "send failed: " << WSAGetLastError() << std::endl;
        }
        
        closesocket(connection_socket);
        connection_socket = INVALID_SOCKET;
    } else
    {
        std::cerr << "Responder called without a valid connection socket." << std::endl;
    }*/
}
