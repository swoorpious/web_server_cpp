//
// Created by Flowey on 26/07/2024.
//

#ifndef PERSISTENTSERVER_H
#define PERSISTENTSERVER_H

#include "../Server.h"
#include <thread>
#include <mutex>

class PersistentServer : public ServerBase {
public:
    PersistentServer(SocketInfo server_info, ListenSocketInfo listen_info) :
        ServerBase(server_info, listen_info) {};

    ~PersistentServer() override {
        ServerBase::Stop();
    }
    void Run() override {
        routing = new RoutingBase();

        while (true) {
            this->Acceptor();
        }
    }

protected:
    void Acceptor() override;
    void Handler() override;

private:
    std::vector<std::thread> client_threads;
    std::mutex client_mutex;
    
};


#endif //PERSISTENTSERVER_H
