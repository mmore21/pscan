#include <stdio.h>

#include "scanner.h"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        scan(argv[1], 1);
    }
    else if (argc > 2)
    {
        fprintf(stderr, "Too many arguments passed.");
    }
    else
    {
        scan("", 0);
    }

    return 0;
}