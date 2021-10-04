cmake_minimum_required(VERSION 3.20)
project(test_client)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_client main.cpp ../lib/errorproc.cpp ../lib/errorproc.h tcpclient.cpp tcpclient.h)
