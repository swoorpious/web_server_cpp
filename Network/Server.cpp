//
// Created by Flowey on 8/07/2024.
//

#include "Server.h"

#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


ServerBase::ServerBase(SocketInfo server_info, ListenSocketInfo listen_info)
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
    routing = new RoutingBase();
        
    while (true)
    {
        Acceptor();
        Handler();

        printf("Server stopped.\n\n");
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
    
    int bytesReceived = recv(connection_socket, recvBuffer, sizeof(recvBuffer) - 1, 0);
    if (bytesReceived > 0)
    {
        Route response_data = routing->ParseRequest(recvBuffer);
        
        recvBuffer[bytesReceived] = '\0';
        printf("Received request:\n");
        printf(recvBuffer);

        
        // temp block
        string httpResponse = FrameResponse(recvBuffer, &response_data);

        send(connection_socket, httpResponse.c_str(), httpResponse.size(), 0);
        // exit(0);
        // return;
    }
    else
        printf("Recv failed or connection closed: " + WSAGetLastError());
    
    closesocket(connection_socket);
}

void ServerBase::Responder() { }

string ServerBase::FrameResponse(char *REQ, const Route *response_data) {
    // istringstream iss(REQ);
    // string METHOD, URL;
    // iss >> METHOD >> URL;

    stringstream RESPONSE;
    string responseBody = ReadFile(response_data->RESPONSE);
    string contentType = GetFileType(response_data->RESPONSE);

    RESPONSE << "HTTP/1.1 200 Ok\r\n";
    RESPONSE << "Content-Type: " << contentType << "\r\n";
    RESPONSE << "Content-Length: " << responseBody.size() << "\r\n";
    RESPONSE << "\r\n";
    RESPONSE << responseBody;

    auto s = RESPONSE.str();
    // const char *k = s.c_str();
    
    return s;
}
