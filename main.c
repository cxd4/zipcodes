#include <stdlib.h>
#include <stdio.h>

#include "zone.h"

int
main(int argc, char* argv[])
{
    unsigned long postal_code;

    if (argc < 2) {
        fputs("Interactive mode not implemented.\n", stderr);
        return 1;
    }
    postal_code = strtoul(argv[1], NULL, 10);
    return zone_trace_by_zip(postal_code);
}
