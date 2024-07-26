cmake_minimum_required(VERSION 3.29)
project(web_server_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(web_server_cpp main.cpp
        main.h
        Network/Socket/Socket.cpp
        Network/Socket/Socket.h
        Network/Socket/ServerSocket.cpp
        Network/Socket/ServerSocket.h
        Network/Server/Server.cpp
        Network/Server/Server.h
        Common/Common.h
        Network/Routing/Routing.cpp
        Network/Routing/Routing.h
        Common/FileFunctions.h
        Network/Server/Persistent/PersistentServer.cpp
        Network/Server/Persistent/PersistentServer.h
        Network/Server/Sequential/SequentialServer.cpp
        Network/Server/Sequential/SequentialServer.h
)
