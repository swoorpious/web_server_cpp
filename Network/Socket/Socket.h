//
// Created by Flowey on 6/07/2024.
//

// https://learn.microsoft.com/en-us/windows/win32/api/_winsock/
// https://webcache.googleusercontent.com/search?q=cache:https://medium.com/from-the-scratch/http-server-what-do-you-need-to-know-to-build-a-simple-http-server-from-scratch-d1ef8945e4fa&strip=0&vwsrc=1&referer=medium-parser


#ifndef SOCKET_H
#define SOCKET_H

#define PORT 6969;

#include "../../Common/Common.h"

namespace WS = CommonNetwork;

class SocketBase
{
public:
    virtual ~SocketBase() = default;
    SocketBase(WS::SocketInfo server_info, u_long ip);
    
    virtual int EstablishConnection(int sock, sockaddr_in address, WS::ListenSocketInfo listen_info) = 0;
    // void close_connection(int sock);
    static void CheckConnection(int sock);
    
    sockaddr_in GetAddress() const { return address; };
    int GetConnection() const { return connection; };
    int GetSock() const { return sock; };

    void SetSock(int sock) { this->sock = sock; };
    void SetConnection(int connection) { this->connection = connection; };
    
protected:
    sockaddr_in address{};
    SOCKET sock = INVALID_SOCKET;
    int connection;
    
};

#endif //SOCKET_H
