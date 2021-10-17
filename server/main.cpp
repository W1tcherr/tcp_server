#include <sys/socket.h>
#include <iostream>
#include "tcpserver.h"


unsigned getPort(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    unsigned port = getPort(argc, argv);
    std::cout << "\n server start on port: " << port << std::endl;
    Tcpserver server(AF_INET, SOCK_STREAM, 0, port);
    server.server_start(5);
    server.sleep_server(1);
    server.server_stop();
    return 0;
}

unsigned getPort(int argc, char *argv[])
{
    if(argc >= 2)
        if(atoi(argv[1]) > 0)
            return atoi(argv[1]);
    return 1603;
}
