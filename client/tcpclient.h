#ifndef CLIENT_SERVER_TCPCLIENT_H
#define CLIENT_SERVER_TCPCLIENT_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "../lib/clientsocketmanager.h"

class Tcpclient : ClientSocketManager
{
public:
    Tcpclient(int domain, int type, int protocol, int port) : ClientSocketManager(domain, type, protocol, port){}

    void client_connect(const char *src);

    void client_disconnect();

    ~Tcpclient();


};


#endif //CLIENT_SERVER_TCPCLIENT_H
