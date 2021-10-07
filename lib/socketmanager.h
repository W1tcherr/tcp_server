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

    static int Socket(int domain, int type, int protocol);

    static ssize_t Read(int fd, void *buf, size_t count);
};

#endif //CLIENT_SERVER_SOCKETMANAGER_H
