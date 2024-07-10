//
// Created by Flowey on 8/07/2024.
//

#include "Server.h"

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
        printf("WSAStartup failed: %d", WSAGetLastError());
        exit(1);
    }
    
    server_socket = new ServerSocket(server_info, INADDR_ANY, listen_info);
    // Run();
}

void ServerBase::Run()
{
    printf("Server Running, waiting for new connection...");

    while (true)
    {
        Acceptor();
        Handler();

        printf("Server stopped.");
    }
    
}


void ServerBase::Acceptor()
{
    printf("Server Accepting...\n");
    sockaddr_in clientAddress;
    int clientAddressLen = sizeof(clientAddress);
    connection_socket = accept(
        server_socket->GetSock(),
        reinterpret_cast<sockaddr*>(&clientAddress),
        &clientAddressLen
        );
    
    if (connection_socket == INVALID_SOCKET)
    {
        std::cerr << "Accept failed: " << WSAGetLastError() << std::endl;
        closesocket(server_socket->GetSock());
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    printf("Connection accepted from %s : %d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));
}

void ServerBase::Handler()
{
    printf("Server handling...\n");

    // char recvBuffer[4096];
    int bytesReceived = recv(connection_socket, recvBuffer, sizeof(recvBuffer) - 1, 0);
    if (bytesReceived > 0)
    {
        recvBuffer[bytesReceived] = '\0';
        printf("Received request:\n");
        printf(recvBuffer);

        // temp block
        const char* httpResponse =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: 43\r\n"
            "\r\n"
            "<html><body>Hello from the server!</body></html>";

        send(connection_socket, httpResponse, strlen(httpResponse), 0);
        // exit(0);
        // return;
    }
    else
        printf("Recv failed or connection closed: " + WSAGetLastError());
    
    closesocket(connection_socket);
}

void ServerBase::Responder() { }
