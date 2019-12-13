#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "scanner.h"

struct sockaddr_in createAddress()
{
    // create an address for the socket
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;

    return address;
}

void scan()
{
    // create a socket
    int network_socket;
    // create a socket address
    struct sockaddr_in address = createAddress();

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

int main()
{
    scan();

    return 0;
}