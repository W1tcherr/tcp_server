#include "tcpserver.h"

void Tcpserver::server_start(int backlog)
{
    server_status = Status::up;
    Bind(this_fd, (struct sockaddr *) &this_address, this_address_len);
    Listen(this_fd, backlog); //backlog = 5
    while (true)
    {
        if (client_fd = Accept(this_fd, (struct sockaddr *) &this_address, &(this_address_len)))
        {
            int _clietn_id = client_id;
            clients.emplace(_clietn_id, std::thread([this, _clietn_id]
                                                   { handle_connection(client_fd, _clietn_id); }));
            ++client_id;
        }
        if (!clients_end.empty())
        {
            for (auto &el: clients_end)
            {
                clients.find(el)->second.join();
                clients.erase(el);
            }
            clients_end.clear();
        }
    }
}

void Tcpserver::handle_connection(int _client_fd, int _client_id)
{
    nread = Read(_client_fd, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, nread);
    write(_client_fd, buf, nread);
    close(_client_fd);
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    clients_end.emplace_back(_client_id);
}

void Tcpserver::server_stop()
{
    server_status = Status::down;
    for(auto& el: clients)
    {
        el.second.join();
        clients.erase(el.first);
    }
    close(this_fd);
}

void Tcpserver::sleep_server(unsigned seconds)
{
    sleep(seconds);
}

Tcpserver::~Tcpserver()
{
    if (server_status == Status::up)
        server_stop();
}