#ifndef CLIENT_SERVER_TCPCLIENT_H
#define CLIENT_SERVER_TCPCLIENT_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "../lib/clientsocketmanager.h"

class Tcpclient
{
    int client_fd;
    ssize_t nread;
    struct sockaddr_in adr = {0};
    char buf[4096];

    enum class Status : bool
    {
        disconnect = false,
        connect = true
    };

    Status connect_status = Status::disconnect;
public:
    Tcpclient(int domain, int type, int protocol, int port);

    void client_connect(const char *src);

    void client_disconnect();

    ~Tcpclient();


};


#endif //CLIENT_SERVER_TCPCLIENT_H
