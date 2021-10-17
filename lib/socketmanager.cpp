#include "socketmanager.h"

SocketManager::SocketManager(int domain, int type, int protocol, unsigned port)
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

bool SocketManager::Read(int fd, char *buf, size_t nbytes, ssize_t &bytes_read)
{
    ssize_t msg_size = 0;
    while ((bytes_read = read(fd, buf + msg_size, nbytes - msg_size - 1)) > 0)
    {
        msg_size += bytes_read;
        if (buf[msg_size - 3] == '#' || buf[msg_size - 1] == '#')
            return false;
        if (msg_size > buf_size - 1 || buf[msg_size - 1] == '\n' || buf[msg_size - 1] == '\0')
            break;
    }
    ProcessError::errorProc(bytes_read, "read failed");
    return true;
}