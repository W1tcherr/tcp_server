#include "tcpclient.h"

void Tcpclient::client_connect(const char *src)
{
    connect_status = Status::connect;
    Inet_pton(this_address.sin_family, src, &this_address.sin_addr); // src = "127.0.0.1"
    Connect(this_fd, (struct sockaddr *) &this_address, this_address_len);
}

void Tcpclient::send_massage(const std::string &client_name, const std::string &msg)
{
    std::string send_msg = getData() + client_name + msg + '\n';
    write(this_fd, send_msg.data(), send_msg.size()+1);
}

void Tcpclient::read_massage()
{
    char *buf = new char[buf_size];
    Read(this_fd, buf, buf_size, bytes_read);
    write(STDOUT_FILENO, buf, bytes_read);
    delete[] buf;
}

std::string Tcpclient::getData()
{
    using namespace std::chrono;
    using namespace std::string_view_literals;

    std::stringstream temp;

    auto const now = system_clock::now();
    auto now_time = system_clock::to_time_t(now);
    auto ms = duration_cast<milliseconds>(now.time_since_epoch()).count() % 1000;
    auto gm_time = std::gmtime(&now_time);

    temp << "["sv
         << std::put_time(gm_time, "%H:%M:%S") << "."sv << ms << " "sv
         << std::put_time(gm_time, "%d.%m.%Y") << "] "sv;

    return temp.str();
}

void Tcpclient::client_disconnect()
{
    connect_status = Status::disconnect;
    write(this_fd, "#", 1);
    close(this_fd);
}

Tcpclient::~Tcpclient()
{
    if (connect_status == Status::connect)
        client_disconnect();
}