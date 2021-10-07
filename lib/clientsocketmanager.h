#ifndef CLIENT_SERVER_CLIENTSOCKETMANAGER_H
#define CLIENT_SERVER_CLIENTSOCKETMANAGER_H

#include "socketmanager.h"

class ClientSocketManager : public SocketManager
{
public:
    enum class Status : bool
    {
        disconnect = false,
        connect = true
    };

    Status connect_status = Status::disconnect;

    ClientSocketManager(int domain, int type, int protocol, int port) : SocketManager(domain, type, protocol, port){}

    void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

    void Inet_pton(int af, const char *src, void *dst);
};

#endif //CLIENT_SERVER_CLIENTSOCKETMANAGER_H
