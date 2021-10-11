#include "tcpclient.h"

void Tcpclient::client_connect(const char *src)
{
    connect_status = Status::connect;
    char* buf = new char[buf_size];
    Inet_pton(this_address.sin_family, src, &this_address.sin_addr); // src = "127.0.0.1"
    Connect(this_fd, (struct sockaddr *) &this_address, this_address_len);
    write(this_fd, "Hello\n", 6);
    nread = Read(this_fd, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, nread);
    delete[] buf;
}

void Tcpclient::client_disconnect()
{
    connect_status = Status::disconnect;
    close(this_fd);
}

Tcpclient::~Tcpclient()
{
    if(connect_status == Status::connect)
        client_disconnect();
}