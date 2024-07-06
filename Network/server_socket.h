//
// Created by Flowey on 6/07/2024.
//

#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H
#include "socket.h"


class ServerSocket: public SocketBase
{
public:
    ServerSocket(int domain, int type, int protocol, int port, u_long local_ip);
;

    int EstablishConnection(int sock, struct sockaddr_in address) override;
};



#endif //SERVER_SOCKET_H
