#ifndef CLIENT_SERVER_TCPCLIENT_H
#define CLIENT_SERVER_TCPCLIENT_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <chrono>
#include <iomanip>
#include <string>
#include "../lib/clientsocketmanager.h"

class Tcpclient : ClientSocketManager
{
    ssize_t bytes_read = 0;

    std::string getData();

public:
    Tcpclient(int domain, int type, int protocol, int port) : ClientSocketManager(domain, type, protocol, port)
    {
    }

    void client_connect(const char *src);

    void send_massage(const std::string &client_name, const std::string &msg);
    void read_massage();

    void client_disconnect();

    ~Tcpclient();


};


#endif //CLIENT_SERVER_TCPCLIENT_H
