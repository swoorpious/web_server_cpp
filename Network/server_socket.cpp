//
// Created by Flowey on 6/07/2024.
//

#include "server_socket.h"


ServerSocket::ServerSocket(int domain, int type, int protocol, int port, u_long local_ip) :
    SocketBase(domain, type, protocol, port, local_ip)
{
    SetConnection(EstablishConnection(GetSock(), GetAddress()));
    CheckConnection(GetConnection());
}


int SocketBase::EstablishConnection(int sock, sockaddr_in address)
{ 
    socklen_t len = sizeof(address);

    return bind(sock, reinterpret_cast<sockaddr *>(&address), len);
}
