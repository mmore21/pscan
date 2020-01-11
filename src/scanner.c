#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "scanner.h"

struct Socket
{
}

struct sockaddr_in createLocalAddress()
{
    // create an address for the socket
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;

    return address;
}

struct sockaddr_in createRemoteAddress(char *ip)
{
    // create an address for the socket
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip);

    return address;
}

void scan(char *ip = "", bool scanRemoteIp = false)
{
    // create a socket
    int network_socket;
    // create a socket address
    if (scanRemoteIp)
    {
        struct sockaddr_in address = createRemoteAddress(ip);
    }
    else
    {
        struct sockaddr_in address = createLocalAddress();
    }

    // loop over range of all tcp ports
    for (int i = 1; i < 65535; i++)
    {
        network_socket = socket(AF_INET, SOCK_STREAM, 0);
        address.sin_port = htons(i);
        
        // attempt to establish connection to port
        int connection_status = connect(network_socket, (struct sockaddr*) &address, sizeof(address));

        if (connection_status == 0)
        {
            printf("tcp\t%d\t open\n", i);
        }

        close(network_socket);
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        scan(argv[1]);
    }
    else if (argc > 2)
    {
        // TODO: Error-handling for when too many parameters were passed.
    }
    else
    {
        scan();
    }

    return 0;
}