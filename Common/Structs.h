#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

// namespace ServerDefinition
// {
    struct ListenSocketInfo {
        bool shouldListen = false;
        int backlog = SOMAXCONN;
    };

    struct SocketInfo {
        int domain = AF_INET;
        int type = SOCK_STREAM;
        int protocol = IPPROTO_TCP;
        int port = 8080;
    };
// }