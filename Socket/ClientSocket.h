//
// Created by Flowey on 6/07/2024.
//

#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H
#include "Socket.h"


class ClientSocket : public SocketBase
{
    public:
    ClientSocket(SocketInfo server, u_long ip, ListenSocketInfo listen);
    
    int EstablishConnection(int sock, sockaddr_in address, ListenSocketInfo listen) override;
};



#endif //CLIENT_SOCKET_H
