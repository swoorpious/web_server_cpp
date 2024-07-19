//
// Created by Flowey on 10/07/2024.
//

#ifndef COMMON_H
#define COMMON_H

#include <cstdlib>
#include <string>
#include <stdexcept>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <unordered_map>

#pragma comment(lib, "ws2_32.lib")

namespace CommonNetwork {
    using namespace std;

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

    struct Query {
        string PARAM;
        string VALUE;
    };

    struct Route {
        string ROUTE;        // destination name
        string RESPONSE;     // file path
        string METHOD; 
        vector<Query> QUERY; // ehhhhh

        Route () :
            ROUTE(""), RESPONSE(""), METHOD("") {}

        Route (const string *route, const string *filePath, const string &method, const vector<Query> *query) :
            ROUTE(*route), RESPONSE(*filePath), METHOD(method), QUERY(*query) {}

        Route(const string *route, const string *filePath, const string &method) :
            ROUTE(*route), RESPONSE(*filePath), METHOD(method) {}
    };

    // std::unordered_map<int, string> StatusCodes = {
    //     {200, "Ok"},
    //     {201, "Created"},
    //     {204, "No Content"},
    //     {400, "Bad Request"},
    //     {401, "Unauthorized"},
    //     {403, "Forbidden"},
    //     {404, "Not Found"},
    //     {405, "Method Not Allowed"},
    //     {500, "Internal Server Error"},
    // };

    inline unordered_map<string, string> ContentTypes = {
        {".html", "text/html"},
        {".css", "text/css"},
        {".js", "application/javascript"},
        {".json", "application/json"},
        {".png", "image/png"},
        {".jpg", "image/jpeg"},
        {".jpeg", "image/jpeg"},
        {".gif", "image/gif"},
        {".svg", "image/svg+xml"},
        {".ico", "image/x-icon"},
        {".webp", "image/webp"},
        {".mp4", "video/mp4"},
        {".mp3", "audio/mpeg"},
        {".wav", "audio/wav"},
        {".ogg", "audio/ogg"},
        {".pdf", "application/pdf"},
        {".zip", "application/zip"},
        {".xml", "application/xml"},
        {".txt", "text/plain"},
    };
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
