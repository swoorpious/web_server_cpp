cmake_minimum_required(VERSION 3.29)
project(web_server_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(web_server_cpp main.cpp
        main.h
        Socket/socket.cpp
        Socket/socket.h
        Socket/server_socket.cpp
        Socket/server_socket.h
        Socket/client_socket.cpp
        Socket/client_socket.h
        Common/structs.h
        Server/server.cpp
        Server/server.h
        Server/test_server.cpp
        Server/test_server.h)
