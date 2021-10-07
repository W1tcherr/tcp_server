#include "tcpserver.h"

void Tcpserver::server_start(int backlog)
{
    server_status = Status::up;
    Bind(this_fd, (struct sockaddr*) &this_address, this_address_len);
    Listen(this_fd, backlog); //backlog = 5
    client_fd = Accept(this_fd, (struct sockaddr*) &this_address, &(this_address_len));
    nread = Read(client_fd, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, nread);
    write(client_fd, buf, nread);
}

void Tcpserver::server_stop()
{
    server_status = Status::down;
    close(client_fd);
    close(this_fd);
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