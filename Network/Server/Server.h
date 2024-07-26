//
// Created by Flowey on 8/07/2024.
//

#ifndef SERVER_H
#define SERVER_H

#define BUFFER_SIZE 4096


#include "../Socket/ServerSocket.h"
#include "../Routing/Routing.h"

#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


class ServerSocket;
class Routing;

class ServerBase {
public:
    virtual ~ServerBase() = default;
    virtual void Stop()
    {
        WSACleanup();
        closesocket(this->connection_socket);
        printf("Server stopped\n");
    };
    ServerSocket* GetServerSocket() const { return server_socket; }
    
    
protected:
    ServerBase(SocketInfo server_info, ListenSocketInfo listen_info);
    virtual void Run() {}
    
    virtual void Acceptor();
    virtual void Handler() {
        // const char * httpResponse = FrameResponse(&response_data).data();
        // send(connection_socket, httpResponse, sizeof(httpResponse), 0);
        
        printf("Server handling...\n");
    };

    static string FrameResponse(const Route *response_data);


    // server shit
    WSADATA wsaData;
    
    ServerSocket *server_socket; // this is what we connect to
    SOCKET connection_socket; // this handles the actual connection
    
    RoutingBase *routing;
    char recvBuffer[BUFFER_SIZE] = " ";
    int result;

};


#endif //SERVER_H
