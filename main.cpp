#include "main.h"
#include <iostream>
#include "Socket/server_socket.h"
#include "Server/server.h"

int main() {

    SocketInfo server_info = { AF_INET, SOCK_STREAM, IPPROTO_TCP, 6969 };
    ListenSocketInfo listen_info = { true, 1024};
    
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Binding Socket..." << std::endl;
    ServerBase* s = new ServerBase(server_info, listen_info);
    s->Run();
    std::cout << "s->Run()" << std::endl;
    
    return 0;
}
