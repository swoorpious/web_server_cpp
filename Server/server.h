//
// Created by Flowey on 8/07/2024.
//

#ifndef SERVER_H
#define SERVER_H

#include <winsock2.h>
// #include "../Common/structs.h"
#include <cstdio>
#include <ws2tcpip.h>
#include "../Socket/server_socket.h"

#pragma comment(lib, "ws2_32.lib")


class ServerSocket;

class ServerBase {
public:
    virtual ~ServerBase() = default;
    ServerBase(/*ServerDefinition::*/SocketInfo server_info, /*ServerDefinition::*/ListenSocketInfo listen_info);
    virtual void Run();
    virtual void Stop()
    {
        WSACleanup();
        closesocket(this->connection_socket);
        printf("Server stopped\n");
    };
    ServerSocket* GetServerSocket() const { return server_socket; }
    
protected:
    virtual void Acceptor();
    virtual void Handler();
    virtual void Responder();
    WSADATA wsaData;


    ServerSocket* server_socket; // this is what we connect to
    SOCKET connection_socket; // this handles the actual connection
    // wtf i need to look into this 🗿

private:
    // const char* hello = "Hello from server";
    // char recvbuf[1024] = "\0";
    // int recvbuf_size = sizeof(recvbuf);
    int result;
};


#endif //SERVER_H
