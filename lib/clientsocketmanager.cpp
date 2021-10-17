#include "clientsocketmanager.h"

void ClientSocketManager::Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int res = connect(sockfd, addr, addrlen);
    ProcessError::errorProc(res, "conncet failed");
}

void ClientSocketManager::Inet_pton(int af, const char *src, void *dst)
{
    int res = inet_pton(af, src, dst);
    ProcessError::errorZero(res,
                            "\n inet_pton failed: src does not contain a character string representing a valid network address in the specified",
                            true);
    ProcessError::errorProc(res, "inet_pton failed");
}