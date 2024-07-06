//
// Created by Flowey on 6/07/2024.
//

/*
 * https://learn.microsoft.com/en-us/windows/win32/winsock/windows-sockets-start-page-2
 */

//https://learn.microsoft.com/en-us/windows/win32/api/_winsock/


#ifndef SOCKET_H
#define SOCKET_H

#include <winsock2.h>
#include <ws2tcpip.h>


class SocketBase
{
public:
    virtual ~SocketBase() = default;
    SocketBase(int domain, int type, int protocol, int port, u_long local_ip);
    
    virtual int EstablishConnection(int sock, struct sockaddr_in address) = 0;
    // void close_connection(int sock);
    static void CheckConnection(int sock);
    
    sockaddr_in GetAddress() const { return address; };
    int GetConnection() const { return connection; };
    int GetSock() const { return sock; };

    void SetSock(int sock) { this->sock = sock; };
    // void set_address(struct sockaddr_in address) { this->address = address; };
    void SetConnection(int connection) { this->connection = connection; };
    
private:
    sockaddr_in address{};
    int sock;
    int connection;
};

#endif //SOCKET_H
