cmake_minimum_required(VERSION 3.29)
project(web_server_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(web_server_cpp main.cpp
        main.h
        Socket/socket.cpp
        Socket/socket.h
        Socket/ServerSocket.cpp
        Socket/ServerSocket.h
        Socket/ClientSocket.cpp
        Socket/ClientSocket.h
        Common/structs.h
        Server/server.cpp
        Server/server.h
        Server/TestServer.cpp
        Server/TestServer.h
        Common/Common.h)
