//
// Created by Flowey on 8/07/2024.
//

#include "Server.h"




ServerBase::ServerBase(SocketInfo server_info, ListenSocketInfo listen_info)
{
    // init Winsock
    result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        printf("WSAStartup failed: %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    
    server_socket = new ServerSocket(server_info, INADDR_ANY, listen_info);
}



void ServerBase::Acceptor()
{
    printf("\nServer Accepting...\n");
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


string ServerBase::FrameResponse(const Route *response_data) {
    stringstream RESPONSE;
    string responseBody = ReadFile(response_data->RESPONSE);
    string contentType = GetFileType(response_data->RESPONSE);

    RESPONSE << "HTTP/1.1 200 Ok\r\n";
    RESPONSE << "Content-Type: " << contentType << "\r\n";
    RESPONSE << "Content-Length: " << responseBody.size() << "\r\n";
    RESPONSE << "\r\n";
    RESPONSE << responseBody;

    return RESPONSE.str();
}
