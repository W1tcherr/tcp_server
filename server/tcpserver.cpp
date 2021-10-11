#include "tcpserver.h"

void Tcpserver::server_start(int backlog)
{
    server_status = Status::up;
    Bind(this_fd, (struct sockaddr*) &this_address, this_address_len);
    Listen(this_fd, backlog); //backlog = 5
    while (true)
    {
        if(client_fd = Accept(this_fd, (struct sockaddr*) &this_address, &(this_address_len)))
        {
            clients.emplace(client_id,std::thread([this]{handle_connection(client_fd, client_id);}));
        }
        if(!clients_end.empty())
        {
            for(auto &el: clients_end)
                clients.erase(el); //std::cout<< el << std::endl;
            clients_end.clear();
        }
        for(auto &el: clients)
            std::cout<<'\n' << el.first << " : " << el.second.get_id();
        std::cout<<'\n' << "client_id: " << client_id << " map_size: " << clients.size() << std::endl;
    }
}

void Tcpserver::handle_connection(int _client_fd, int _client_id)
{
    ++client_id;
    nread = Read(_client_fd, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, nread);
    write(_client_fd, buf, nread);
    close(_client_fd);
    std::cout<<'\n' << "client_id: " << _client_id << std::endl;
    clients_end.emplace_back(_client_id);
}

void Tcpserver::server_stop()
{
    server_status = Status::down;
    //close(client_fd);
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