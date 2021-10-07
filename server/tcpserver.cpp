#include "tcpserver.h"

Tcpserver::Tcpserver(int domain, int type, int protocol, int port)
{
    server_fd = ServerSocketManager::Socket(domain, type, protocol); //(AF_INET, SOCK_STREAM, 0)
    server_address.sin_family = domain; //AF_INET
    server_address.sin_port = htons(port);
    server_address_len = sizeof(server_address);
}

void Tcpserver::server_start(int backlog)
{
    server_status = Status::up;
    ServerSocketManager::Bind(server_fd, (struct sockaddr*) &server_address, server_address_len);
    ServerSocketManager::Listen(server_fd, backlog); //backlog = 10
    client_fd = ServerSocketManager::Accept(server_fd, (struct sockaddr*) &server_address, &(server_address_len));
    nread = ServerSocketManager::Read(client_fd, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, nread);
    write(client_fd, buf, nread);
}

void Tcpserver::server_stop()
{
    server_status = Status::down;
    close(client_fd);
    close(server_fd);
}

void Tcpserver::sleep_server(unsigned seconds)
{
    sleep(seconds);
}

Tcpserver::~Tcpserver()
{
    if(server_status == Status::up)
        server_stop();
}