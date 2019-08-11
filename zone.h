#ifndef _ZONE_H_
#define _ZONE_H_

#include <limits.h>

typedef struct {
#if (UINT_MAX < 99999U)
#define ZIP_MAX ULONG_MAX
    unsigned long zip_min;
    unsigned long zip_max;
#else
#define ZIP_MAX UINT_MAX
    unsigned int zip_min;
    unsigned int zip_max;
#endif
    const char abbr[3];
} state;


extern int zone_trace_by_zip(unsigned long zip_code);

#endif
