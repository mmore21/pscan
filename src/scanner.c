#include "scanner.h"

struct sockaddr_in create_address(char *ip)
{
    // Create an address for the socket
    struct sockaddr_in address;
    address.sin_family = AF_INET;

    // Set local vs remote address whether ip is provided
    if (ip && !ip[0])
    {
        address.sin_addr.s_addr = INADDR_ANY;
    }
    else
    {
        address.sin_addr.s_addr = inet_addr(ip);
    }

    return address;
}

void scan(char *ip)
{
    // Create a socket
    int network_socket;
    struct sockaddr_in address;

    // Create a socket address
    address = create_address(ip);

    // Loop over range of all tcp ports
    for (int port = 1; port < MAX_PORT; port++)
    {
        network_socket = socket(AF_INET, SOCK_STREAM, 0);
        address.sin_port = htons(port);

        // Attempt to establish connection to port
        int status = connect(network_socket, (struct sockaddr*) &address, sizeof(address));

        // Socket successfully connected
        if (status == 0)
        {
            printf("tcp\t%d\t open\n", port);
        }

        close(network_socket);
    }
}

