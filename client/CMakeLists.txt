cmake_minimum_required(VERSION 3.20)
project(test_client)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_client main.cpp tcpclient.cpp tcpclient.h ../lib/socketmanager.cpp ../lib/socketmanager.h
                ../lib/processerror.cpp ../lib/processerror.h ../lib/clientsocketmanager.cpp ../lib/clientsocketmanager.h)
