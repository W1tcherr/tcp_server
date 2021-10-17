#include <sys/socket.h>
#include "tcpclient.h"

unsigned getPort(char *str);

unsigned getSecond(char *str);

int main(int argc, char *argv[])
{
    std::string name = "Client";
    unsigned port = 1603;
    unsigned seconds = 1;
    if (argc > 2)
    {
        for (int i = 1; i < 4 && argv[i]; ++i)
            switch (i)
            {
                case 1:
                    name = argv[i];
                    break;
                case 2:
                    port = getPort(argv[i]);
                    break;
                case 3:
                    seconds = getSecond(argv[i]);
                    break;
                default:
                    break;
            }
    }
    std::cout << "Client start with: Name - " << name  << "; Port - " << port << "; auto send time(s) - " << seconds << std::endl;
    Tcpclient client(AF_INET, SOCK_STREAM, 0, 1604);
    client.client_connect("127.0.0.1");
    for(unsigned i = 0; i < 10; ++i)
    {
        client.send_massage(name,"");
        client.read_massage();
        sleep(seconds);
    }
    client.client_disconnect();
    return 0;
}

unsigned getPort(char *str)
{
    if (atoi(str) > 0)
        return atoi(str);
    return 1603;
}

unsigned getSecond(char *str)
{
    if (atoi(str) > 0)
        return atoi(str);
    return 1;
}