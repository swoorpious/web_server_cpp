//
// Created by Flowey on 26/07/2024.
//

#include "SequentialServer.h"



void SequentialServer::Handler() {
    ServerBase::Handler();

    int bytesReceived = recv(connection_socket, recvBuffer, sizeof(recvBuffer) - 1, 0);
    if (bytesReceived > 0) {
        const Route response_data = routing->ParseRequest(recvBuffer);
        const string httpResponse = FrameResponse(&response_data);

        recvBuffer[bytesReceived] = '\0';
        printf("Received request:\n");
        printf(recvBuffer);

        send(connection_socket, httpResponse.c_str(), httpResponse.size(), 0);

    }
    else printf("Recv failed or connection closed: " + WSAGetLastError());

    closesocket(connection_socket);
}


