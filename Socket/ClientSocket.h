//
// Created by Flowey on 6/07/2024.
//

#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H
#include "Socket.h"


class ClientSocket : public SocketBase
{
    public:
    ClientSocket(CommonSock::SocketInfo server, u_long ip, CommonSock::ListenSocketInfo listen);
    
    int EstablishConnection(int sock, sockaddr_in address, CommonSock::ListenSocketInfo listen) override;
};



#endif //CLIENT_SOCKET_H
