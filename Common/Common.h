//
// Created by Flowey on 10/07/2024.
//

#ifndef COMMON_H
#define COMMON_H

#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

namespace CommonSock {
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
}

namespace CommonRoute {
    using namespace std;
    struct Query {
        string PARAM;
        string VALUE;
    };

    struct Route {
        string ROUTE;    // destination name
        string RESPONSE; // takes in string& request — return a file path
        vector<Query> QUERY;

        Route () {
            ROUTE = "";
            RESPONSE = "index.html";
        }

        Route (const string *route, const string *response, const vector<Query> *query) {
            ROUTE = *route;
            RESPONSE = *response;
            QUERY = *query;
        }
    };


    inline std::vector<Route> RouteHead;
}

/*namespace CommonMem
{
    template <typename T, typename U> 
    T* AllocateBuffer(size_t BUFFER_SIZE, U INIT_BUFFER_VALUE)
    {
        try {
            T *buffer = static_cast<T *>(std::malloc(sizeof(T) * BUFFER_SIZE));

            if (buffer == nullptr) 
                throw std::bad_alloc();

            for (size_t i = 0; i < BUFFER_SIZE; i++) 
                buffer[i] = static_cast<T>(INIT_BUFFER_VALUE);
                
            // std::memset(buffer, 0, sizeof(T) * BUFFER_SIZE);
            return buffer;
        } catch (std::bad_alloc& e) {
            throw printf("Memory allocation failed: %s\n", e.what());
        }
        
    };

    template <typename T>
    T* AllocateNullBuffer(size_t BUFFER_SIZE) {
        return AllocateBuffer<int, int>(BUFFER_SIZE, 0);
    }
    
    void ClearBuffer() {
        
    };
    
    void FreeBuffer() {
        
    };
}*/


#endif //COMMON_H
