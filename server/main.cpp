#include <sys/socket.h>
#include "tcpserver.h"

int main() {
    Tcpserver server(AF_INET, SOCK_STREAM, 0, 1603);
    server.server_start(5);
    server.sleep_server(1);
    server.server_stop();
    return 0;
}
