#include "errorproc.h"

void ErrorProc::errorProc(const int& res, const char* msg) //ProcessError::processError
{
    if(res == -1) // ERROR_CODE = -1
    {
        perror(msg);
        exit(EXIT_FAILURE);
    }
}

void ErrorProc::errorZero(const int& res, const char* msg, bool Exit) //ProcessError::processZero
{
    if(res == 0) // ERROR_ZERO_CODE = 0
    {
        std::cout << msg << std::endl;
        if(Exit)
            exit(EXIT_FAILURE);
    }
}

int ErrorProc::Socket(int domain, int type, int protocol)
{
    int res = socket(domain, type, protocol);
    errorProc(res, "socket failed");
    return res;
}

void ErrorProc::Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int res = bind(sockfd, addr, addrlen);
    errorProc(res, "bind failed");
}

void ErrorProc::Listen(int sockfd, int backlog)
{
    int res = listen(sockfd, backlog);
    errorProc(res, "listen failed");
}

int ErrorProc::Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int res = accept(sockfd, addr, addrlen);
    errorProc(res, "accept failed");
    return res;
}

void ErrorProc::Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int res = connect(sockfd, addr, addrlen);
    errorProc(res, "conncet failed");
}

void ErrorProc::Inet_pton(int af, const char *src, void *dst)
{
    int res = inet_pton(af, src, dst);
    errorZero(res, "\n inet_pton failed: src does not contain a character string representing a valid netwo rk address in the specified", 1);
    errorProc(res, "inet_pton failed");
}

ssize_t ErrorProc::Read(int fd, void *buf, size_t count)
{
    ssize_t nread = read(fd, buf, 256);
    errorProc(nread, "read failed");
    errorZero(nread, "end of file", 0);
    return nread;
}