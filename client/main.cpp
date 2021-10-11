#include <sys/socket.h>
#include "tcpclient.h"

int main() {
    Tcpclient client(AF_INET, SOCK_STREAM, 0, 1603);
    client.client_connect("127.0.0.1");
    client.client_disconnect();
    return 0;
}
