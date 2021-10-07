#include "tcpclient.h"

Tcpclient::Tcpclient(int domain, int type, int protocol, int port)
{
    client_fd = ClientSocketManager::Socket(domain, type, protocol);
    adr.sin_family = domain;
    adr.sin_port = htons(port);
}

void Tcpclient::client_connect(const char *src)
{
    connect_status = Status::connect;
    ClientSocketManager::Inet_pton(adr.sin_family, src, &adr.sin_addr); // src = "127.0.0.1"
    ClientSocketManager::Connect(client_fd, (struct sockaddr *) &adr, sizeof(adr));
    write(client_fd, "Hello\n", 6);
    nread = ClientSocketManager::Read(client_fd, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, nread);
}

void Tcpclient::client_disconnect()
{
    connect_status = Status::disconnect;
    close(client_fd);
}

Tcpclient::~Tcpclient()
{
    if(connect_status == Status::connect)
        client_disconnect();
}