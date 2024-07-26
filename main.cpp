#include "main.h"
#include <iostream>
#include "Network/Socket/ServerSocket.h"
#include "Network/Server/Sequential/SequentialServer.h"



void RunSequentialServer() {
    SocketInfo server_info = {AF_INET, SOCK_STREAM, IPPROTO_TCP, 80};
    ListenSocketInfo listen_info = {true, 1024};
    
    auto* s = new SequentialServer(server_info, listen_info);
    s->Run();

}


int main() {
    RunSequentialServer();
    return 0;
}
