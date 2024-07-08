//
// Created by Flowey on 6/07/2024.
//

// TODO: implement listening, and server object

#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H
#include "socket.h"



class ServerSocket : public SocketBase
{
private:
    // int backlog;
    // int listen;
public:
    ServerSocket(SocketInfo server_info, u_long ip, ListenSocketInfo listen_info);
    
    int EstablishConnection(int sock, struct sockaddr_in address, ListenSocketInfo listen) override;
};



#endif //SERVER_SOCKET_H
