#ifndef CLIENT_SERVER_SERVERSOCKETMANAGER_H
#define CLIENT_SERVER_SERVERSOCKETMANAGER_H

#include "socketmanager.h"

class ServerSocketManager : public SocketManager
{
public:
    static void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

    static void Listen(int sockfd, int backlog);

    static int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
};


#endif //CLIENT_SERVER_SERVERSOCKETMANAGER_H
