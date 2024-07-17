//
// Created by Flowey on 6/07/2024.
//

#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H
#include "Socket.h"


class ServerSocket : public SocketBase
{
private:
    // int backlog;
    // int listen;
public:
    ServerSocket(WS::SocketInfo server_info, u_long ip, WS::ListenSocketInfo listen_info);
    
    int EstablishConnection(int sock, struct sockaddr_in address, WS::ListenSocketInfo listen) override;
};



#endif //SERVER_SOCKET_H
