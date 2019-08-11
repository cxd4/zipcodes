#include <stdio.h>
#include "zone.h"

static const state states[] = {
    {     0, ZIP_MAX, "??" }, /* invalid US postal code */
    { 00000, 99999, "US" }, /* unable to classify zone */
    {     0,    99, "--" },
    {   100,   199, "??" }, /* outside the United States */
    {   210,   215, "--" }, /* no longer used by USA */

    {   501,   599, "--" }, /* Holtsville, NY IRS center */
    {   600,   999, "PR" }, /* Puerto Rico (except 008nn) */
    {   800,   899, "VI" }, /* U.S. Virgin Islands */

    {  1000,  2799, "MA" }, /* also 055nn */
    {  2800,  2999, "RI" },
    {  3000,  3899, "NH" },
    {  3900,  4999, "ME" },
    {  5000,  5999, "VT" }, /* except 055nn */
    {  5500,  5599, "--" }, /* Andover, MA */

    {  6000,  6999, "CT" }, /* except 06390 */
    {  6390,  6390, "--" }, /* Fishers Island, NY; served from CT */
    {  7000,  8999, "NJ" },
    {  9000,  9899, "AE" }, /* Army/Fleet PO Europe & Middle East */
    { 10000, 14999, "NY" }, /* also 005nn, 06390 */

    { 15000, 19699, "PA" },
    { 19700, 19999, "DE" },

    { 20000, 20599, "DC" }, /* also 569nn; 201nn/20588/20598 invalid */
    { 20100, 20199, "--" }, /* Dulles, VA */
    { 20588, 20588, "MD" },
    { 20598, 20598, "VA" },
    { 20600, 21999, "MD" }, /* also 20588 (213nn not in use) */
    { 22000, 24699, "VA" }, /* also 20598 and 201nn */

    { 24700, 26899, "WV" },
    { 27000, 28999, "NC" },
    { 29000, 29999, "SC" },

    { 30000, 31999, "GA" }, /* also 398nn, 399nn */
    { 32000, 34999, "FL" }, /* except 340nn, (343nn, 345nn, 348nn not in use) */
    { 34000, 34099, "AA" }, /* Army/Fleet PO Americas */
    { 35000, 36999, "AL" }, /* 353nn not in use */
    { 37000, 38599, "TN" },
    { 38600, 39799, "MS" },
    { 39800, 39999, "--" }, /* Albany, GA and Atlanta, GA */

    { 40000, 42799, "KY" }, /* 419nn not in use */
    { 43000, 45999, "OH" },
    { 46000, 47999, "IN" },
    { 48000, 49999, "MI" },

    { 50000, 52899, "IA" }, /* 517nn - 519nn not in use */
    { 53000, 54999, "WI" }, /* 533nn and 536nn not in use */
    { 55000, 56799, "MN" }, /* 552nn not in use */
    { 56900, 56999, "--" }, /* parcel returns processing for DC */
    { 57000, 57799, "SD" },
    { 58000, 58899, "ND" },
    { 59000, 59999, "MT" },

    { 60000, 62999, "IL" }, /* 621nn not in use */
    { 63000, 65899, "MO" }, /* 632nn, 642nn, 643nn not in use */
    { 66000, 67999, "KS" }, /* 663nn not in use */
    { 68000, 69399, "NE" }, /* 682nn not in use */

    { 70000, 71499, "LA" }, /* 702nn, 709nn not in use */
    { 71600, 72999, "AR" },
    { 73000, 74999, "OK" }, /* except 73960 and 733nn (732/742nn not in use) */
    { 73300, 73399, "--" }, /* Austin, TX */
    { 73960, 73960, "--" }, /* Texhoma, TX */
    { 75000, 79999, "TX" }, /* also 733nn/73960 and 885nn (771nn not in use) */

    { 80000, 81699, "CO" },
    { 82000, 83199, "WY" }, /* also 83414 */
    { 83200, 83899, "ID" }, /* except 83414 */
    { 83414, 83414, "--" }, /* Alta, WY */

    { 84000, 84799, "UT" },
    { 85000, 86599, "AZ" }, /* 854nn, 858nn, 861nn, 862nn not in use */
    { 87000, 88499, "NM" }, /* 872nn (and probably 876nn?) not in use */
    { 88500, 88599, "--" }, /* El Paso, TX */
    { 88900, 89899, "NV" }, /* 892nn, 896nn not in use */

    { 90000, 96199, "CA" }, /* 909nn, 929nn not in use */
    { 96200, 96699, "AP" }, /* Army/Fleet PO Pacific */
    { 96700, 96899, "HI" }, /* except 96799 */
    { 96799, 96799, "AS" }, /* American Somoa */

    { 96910, 96932, "GU" }, /* Guam */
    { 96939, 96940, "PW" }, /* Palau */
    { 96941, 96944, "FM" }, /* Federated States of Micronesia */
    { 96950, 96952, "MP" }, /* Commonwealth of the Northern Mariana Islands */
    { 96960, 96970, "MH" }, /* Marshall Islands */
    { 97000, 97999, "OR" },
    { 98000, 99499, "WA" }, /* 987nn not in use */
    { 99500, 99999, "AK" },
};

int
zone_trace_by_zip(unsigned long zip_code)
{
    register size_t i;
    size_t j = 0;

    for (i = 0; i < sizeof(states) / sizeof(state); i++) {
        if (
            zip_code >= states[i].zip_min
         && zip_code <= states[i].zip_max
        ) {
            j = i;
        }
    }
    fputs("Zone belonging to state:  ", stdout);
    puts(states[j].abbr);
    return 0;
}
