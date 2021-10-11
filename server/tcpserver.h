#ifndef CLIENT_SERVER_TCPSERVER_H
#define CLIENT_SERVER_TCPSERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <map>
#include <vector>
#include <string.h>
#include <thread>
#include "../lib/serversocketmanager.h"

class Tcpserver : ServerSocketManager
{
    int client_id = 0;
    std::map<int, std::thread> clients;
    std::vector<int> clients_end{};

public:
    Tcpserver(int domain, int type, int protocol, int port) : ServerSocketManager(domain, type, protocol, port)
    {
    }

    void server_start(int backlog);

    void server_stop();

    void sleep_server(unsigned seconds);

    void handle_connection(int _client_fd, int _client_id);

    ~Tcpserver();
};


#endif //CLIENT_SERVER_TCPSERVER_H
