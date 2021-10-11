cmake_minimum_required(VERSION 3.20)
project(test_server)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_server main.cpp ../lib/serversocketmanager.cpp ../lib/serversocketmanager.h
                ../lib/processerror.cpp ../lib/processerror.h ../lib/socketmanager.cpp ../lib/socketmanager.h
                tcpserver.cpp tcpserver.h)
target_link_libraries(test_server pthread)