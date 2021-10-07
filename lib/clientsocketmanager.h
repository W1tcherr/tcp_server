#ifndef CLIENT_SERVER_CLIENTSOCKETMANAGER_H
#define CLIENT_SERVER_CLIENTSOCKETMANAGER_H

#include "socketmanager.h"

class ClientSocketManager : public SocketManager
{
public:
    static void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

    static void Inet_pton(int af, const char *src, void *dst);
};

#endif //CLIENT_SERVER_CLIENTSOCKETMANAGER_H
