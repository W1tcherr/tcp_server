cmake_minimum_required(VERSION 3.20)
project(test_server)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_server main.cpp ../lib/errorproc.cpp ../lib/errorproc.h tcpserver.cpp tcpserver.h)
