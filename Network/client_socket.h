//
// Created by Flowey on 6/07/2024.
//

#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H
#include "socket.h"


class ClientSocket : public SocketBase
{
    public:
    ClientSocket(int domain, int type, int protocol, int port, u_long local_ip);
    
    int EstablishConnection(int sock, struct sockaddr_in address) override;
};



#endif //CLIENT_SOCKET_H
