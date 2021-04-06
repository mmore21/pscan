#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORT 65535

struct sockaddr_in create_address(char *ip);
void scan(char *ip);

#endif

