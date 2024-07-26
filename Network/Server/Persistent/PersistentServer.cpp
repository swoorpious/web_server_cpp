//
// Created by Flowey on 26/07/2024.
//

#include "PersistentServer.h"

void PersistentServer::Acceptor() {
    ServerBase::Acceptor();

    std::lock_guard lock(client_mutex);
    client_threads.emplace_back([this]() { this->Handler(); });
}

void PersistentServer::Handler() {
    char buffer[BUFFER_SIZE];
    int bytesReceived;

    while ((bytesReceived = recv(connection_socket, recvBuffer, sizeof(recvBuffer) - 1, 0)) > 0) {
        const Route response_data = routing->ParseRequest(recvBuffer);
        const string httpResponse = FrameResponse(&response_data);
        
        recvBuffer[bytesReceived] = '\0';
        printf("Received request:\n");
        printf(recvBuffer);

        // Send the response to the client
        send(connection_socket, httpResponse.c_str(), httpResponse.size(), 0);
    }

    if (result == 0) {
        printf("Connection closing...\n");
    }
    else if (result == SOCKET_ERROR) {
        printf("recv failed: %d\n", WSAGetLastError());
    }

    closesocket(connection_socket);
    printf("Client disconnected.\n");
}
