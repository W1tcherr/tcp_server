#ifndef CLIENT_SERVER_SOCKETMANAGER_H
#define CLIENT_SERVER_SOCKETMANAGER_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "processerror.h"

class SocketManager
{
public:
    int this_fd;
    struct sockaddr_in this_address = {0};
    socklen_t this_address_len;
    int buf_size = 4096;

    SocketManager(int domain, int type, int protocol, unsigned port);

    int Socket(int domain, int type, int protocol);

    bool Read(int fd, char *buf, size_t count, ssize_t &bytes_read);
};

#endif //CLIENT_SERVER_SOCKETMANAGER_H
