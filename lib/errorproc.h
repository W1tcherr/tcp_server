#ifndef CLIENT_SERVER_ERRORPROC_H
#define CLIENT_SERVER_ERRORPROC_H
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class ErrorProc { //SocetManager

    static void errorProc(const int& res, const char* msg);
    static void errorZero(const int& res, const char* msg, bool Exit);

public:

    static int Socket(int domain, int type, int protocol); //SocetManager

    static void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

    static void Listen(int sockfd, int backlog);

    static int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

    static void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

    static void Inet_pton(int af, const char *src, void *dst);

    static ssize_t Read(int fd, void *buf, size_t count); //SocetManager

};

#endif //CLIENT_SERVER_ERRORPROC_H
