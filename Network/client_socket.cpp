//
// Created by Flowey on 6/07/2024.
//

#include "client_socket.h"


ClientSocket::ClientSocket(int domain, int type, int protocol, int port, u_long local_ip) :
    SocketBase(domain, type, protocol, port, local_ip)
{
    SetConnection(EstablishConnection(GetSock(), GetAddress()));
    CheckConnection(GetConnection());
}


int ClientSocket::EstablishConnection(int sock, struct sockaddr_in address)
{
    socklen_t len = sizeof(address);

    return connect(sock, reinterpret_cast<sockaddr *>(&address), len);
}
