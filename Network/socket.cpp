//
// Created by Flowey on 6/07/2024.
//

#include "socket.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


SocketBase::SocketBase(int domain, int type, int protocol, int port, u_long local_ip)
{
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(local_ip);

    try
    {
        sock = socket(domain, type, protocol);
        CheckConnection(sock);
        // connection = SocketBase::EstablishConnection(sock, address);
    }
    catch (int)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }


    // if (connection == INVALID_SOCKET)
}


void SocketBase::CheckConnection(int sock)
{
    if (sock < 0) exit(EXIT_FAILURE);
}



