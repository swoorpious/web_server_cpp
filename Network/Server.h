//
// Created by Flowey on 8/07/2024.
//

#ifndef SERVER_H
#define SERVER_H

#define BUFFER_SIZE 4096


#include "Socket/ServerSocket.h"
#include "Routing/Routing.h"

class ServerSocket;
class Routing;

class ServerBase {
public:
    virtual ~ServerBase() = default;
    ServerBase(SocketInfo server_info, ListenSocketInfo listen_info);
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
    virtual void Responder() { };

    static string FrameResponse(const Route *response_data);
    
    WSADATA wsaData;
    
    ServerSocket *server_socket; // this is what we connect to
    SOCKET connection_socket; // this handles the actual connection
    
private:
    char recvBuffer[BUFFER_SIZE] = " ";
    int result;

    RoutingBase *routing;
};


#endif //SERVER_H
