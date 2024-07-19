cmake_minimum_required(VERSION 3.29)
project(web_server_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(web_server_cpp main.cpp
        main.h
        Network/Socket/Socket.cpp
        Network/Socket/Socket.h
        Network/Socket/ServerSocket.cpp
        Network/Socket/ServerSocket.h
        Network/Server.cpp
        Network/Server.h
        Common/Common.h
        Network/Routing/Routing.cpp
        Network/Routing/Routing.h
        Common/FileFunctions.h
        Common/json.hpp
)
