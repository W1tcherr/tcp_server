#include "socketmanager.h"

SocketManager::SocketManager(int domain, int type, int protocol, int port)
{
    this_fd = Socket(domain, type, protocol);
    this_address.sin_family = domain;
    this_address.sin_port = port;
    this_address_len = sizeof(this_address);
}

int SocketManager::Socket(int domain, int type, int protocol)
{
    int res = socket(domain, type, protocol);
    ProcessError::errorProc(res, "socket failed");
    return res;
}

ssize_t SocketManager::Read(int fd, void *buf, size_t count)
{
    ssize_t nread = read(fd, buf, 256);
    ProcessError::errorProc(nread, "read failed");
    ProcessError::errorZero(nread, "end of file", false);
    return nread;
}