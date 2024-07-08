//
// Created by Flowey on 6/07/2024.
//

#include "socket.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


SocketBase::SocketBase(SocketInfo server_info, u_long ip)
{
    
    auto [domain, type, protocol, port] = server_info;
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(ip);

    
    try
    {
        sock = socket(domain, type, protocol);
        // connection = SocketBase::EstablishConnection(sock, address);
    }
    catch (int)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

}


void SocketBase::CheckConnection(int sock)
{
    if (sock < 0) exit(EXIT_FAILURE);
}



