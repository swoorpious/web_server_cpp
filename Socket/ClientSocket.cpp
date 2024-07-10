//
// Created by Flowey on 6/07/2024.
//

#include "ClientSocket.h"


ClientSocket::ClientSocket(SocketInfo server, u_long ip, ListenSocketInfo listen) :
    SocketBase(server, ip)
{
    // auto [domain, type, protocol, port] = server;

    this->connection = EstablishConnection(this->sock, this->address, listen);
    CheckConnection(this->connection);
}


int ClientSocket::EstablishConnection(int sock, struct sockaddr_in address, ListenSocketInfo listen)
{
    // socklen_t len = sizeof(address);
    // return connect(sock, reinterpret_cast<sockaddr *>(&address), len);
    return 0;
}