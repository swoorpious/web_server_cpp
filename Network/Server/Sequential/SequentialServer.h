//
// Created by Flowey on 26/07/2024.
//

#ifndef SEQUENTIALSERVER_H
#define SEQUENTIALSERVER_H

#include "../Server.h"


class SequentialServer : public ServerBase {
public:
    SequentialServer(SocketInfo server_info, ListenSocketInfo listen_info)
    : ServerBase(server_info, listen_info) {};
    
    void Run() override;

protected:
    void Acceptor() override {
        ServerBase::Acceptor();
    }
    void Handler() override;


};


#endif //SEQUENTIALSERVER_H
