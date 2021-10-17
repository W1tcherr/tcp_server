#include "serversocketmanager.h"

void ServerSocketManager::Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int res = bind(sockfd, addr, addrlen);
    ProcessError::errorProc(res, "bind failed");
}

void ServerSocketManager::Listen(int sockfd, int backlog)
{
    int res = listen(sockfd, backlog);
    ProcessError::errorProc(res, "listen failed");
}

int ServerSocketManager::Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int res = accept(sockfd, addr, addrlen);
    ProcessError::errorProc(res, "accept failed");
    return res;
}