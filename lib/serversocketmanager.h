#ifndef CLIENT_SERVER_SERVERSOCKETMANAGER_H
#define CLIENT_SERVER_SERVERSOCKETMANAGER_H

#include "socketmanager.h"

class ServerSocketManager : public SocketManager
{
public:
    int client_fd;

    enum class Status : bool
    {
        down = false,
        up = true
    };

    Status server_status = Status::down;

    ServerSocketManager(int domain, int type, int protocol, unsigned port) : SocketManager(domain, type, protocol, port){}

    void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

    void Listen(int sockfd, int backlog);

    int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
};

#endif //CLIENT_SERVER_SERVERSOCKETMANAGER_H
