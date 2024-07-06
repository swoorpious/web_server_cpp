cmake_minimum_required(VERSION 3.29)
project(web_server_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(web_server_cpp main.cpp
        main.h
        Network/socket.cpp
        Network/socket.h
        Network/server_socket.cpp
        Network/server_socket.h
        Network/client_socket.cpp
        Network/client_socket.h)
