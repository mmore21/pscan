#ifndef SCANNER_H
#define SCANNER_H

struct sockaddr_in createRemoteAddress(char *ip);

struct sockaddr_in createLocalAddress();

void scan(char *ip, int scanRemoteIp);

#endif