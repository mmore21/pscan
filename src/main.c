#include <stdlib.h>

#include "scanner.h"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        scan(argv[1]);
    }
    else if (argc > 2)
    {
        fprintf(stderr, "Too many arguments passed.");
        exit(1);
    }
    else
    {
        scan("");
    }

    exit(0);
}

