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
            int _client_fd = client_fd;
            int _client_id = client_id++;
            clients.emplace(_client_id, std::thread([this, _client_id, _client_fd]
                                                    { handle_connection(_client_fd, _client_id); }));
        }
        cleaning_clients();
        std::cout << "\nmap size: " << clients.size();
        for (auto &el: clients)
        {
            std::cout << "\nclients id: " << el.first << "\tthread_id: " << el.second.get_id() << std::endl;
        }
    }
}

void Tcpserver::handle_connection(int _client_fd, int _client_id)
{
    ssize_t bytes_read = 0;
    char *buf = new char[buf_size];
    bool end_connection = true;
    while (end_connection)
    {
        end_connection = Read(_client_fd, buf, buf_size, bytes_read);
        write(STDOUT_FILENO, buf, bytes_read);
        write(_client_fd, buf, bytes_read);
    }
    close(_client_fd);
    delete[] buf;
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    clients_end.emplace_back(_client_id);
}

void Tcpserver::cleaning_clients()
{
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

void Tcpserver::server_stop()
{
    server_status = Status::down;
    for (auto &el: clients)
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