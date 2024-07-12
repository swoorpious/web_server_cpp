//
// Created by Flowey on 6/07/2024.
//

// https://learn.microsoft.com/en-us/windows/win32/api/_winsock/
// https://webcache.googleusercontent.com/search?q=cache:https://medium.com/from-the-scratch/http-server-what-do-you-need-to-know-to-build-a-simple-http-server-from-scratch-d1ef8945e4fa&strip=0&vwsrc=1&referer=medium-parser


#ifndef SOCKET_H
#define SOCKET_H

#define PORT 6969;

#include <winsock2.h>
#include "../Common/Common.h"
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")



class SocketBase
{
public:
    virtual ~SocketBase() = default;
    SocketBase(CommonSock::SocketInfo server_info, u_long ip);
    
    virtual int EstablishConnection(int sock, sockaddr_in address, CommonSock::ListenSocketInfo listen_info) = 0;
    // void close_connection(int sock);
    static void CheckConnection(int sock);
    
    sockaddr_in GetAddress() const { return address; };
    int GetConnection() const { return connection; };
    int GetSock() const { return sock; };

    void SetSock(int sock) { this->sock = sock; };
    // void set_address(struct sockaddr_in address) { this->address = address; };
    void SetConnection(int connection) { this->connection = connection; };
    
protected:
    sockaddr_in address{};
    SOCKET sock = INVALID_SOCKET;
    int connection;
    
};

#endif //SOCKET_H
