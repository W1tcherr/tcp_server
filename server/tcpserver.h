#ifndef CLIENT_SERVER_TCPSERVER_H
#define CLIENT_SERVER_TCPSERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <list>
#include <string.h>
#include "../lib/errorproc.h"

class Tcpserver
{
    int server_fd;
    int client_fd;
    ssize_t nread;
    char buf[4096];
    struct sockaddr_in server_address = {0};
    socklen_t server_address_len;

    enum class Status : bool
    {
        down = false,
        up = true
    };

    Status server_status = Status::down;

   /* struct Client
    {
        static inline int client_id = 0;
        int client_fd;
        sockaddr_in client_address = {0};
        char client_buf[4096];
        char* client_answer;
        socklen_t client_address_len;

        Client(int _client_fd)
        {
            ++client_id;
            client_fd = _client_fd;
            memset(&(client_address.sin_zero), 0, 8); //???
            client_answer = new char[4096]{};
            client_address_len = sizeof(client_address);
        }
    };

    std::list<Client> clients;*/

public:
    Tcpserver(int domain, int type, int protocol, int port);

    void server_start(int backlog);

    void server_stop();

    void sleep_server(unsigned seconds);

    ~Tcpserver();
};


#endif //CLIENT_SERVER_TCPSERVER_H
