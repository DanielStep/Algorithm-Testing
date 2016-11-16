//
//  record.h
//   
//
//  Created by Daniel Stepanenko on 15/04/2016.
//   
//

#ifndef record_h
#define record_h

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define IDLEN 8
#define CASELEN 8
#define DATELEN sizeof(time_t) 
#define BLOCKLEN 38
#define IUCRLEN 4
#define TYPELEN 33
#define DESCLEN 59
#define LOC_DESC_LEN 47
#define ARREST_LEN sizeof (bool) 
#define DOMESTIC_LEN sizeof (bool) 
#define BEATLEN 10
#define DISTRICTLEN 10
#define WARDLEN 5
#define COMM_AREA_LEN 5
#define FBI_CODE_LEN 4

#define NUM_FIELDS 15

struct record{
    char id[IDLEN + 1];
    char case_no[CASELEN + 1];
    time_t date;
    char block[BLOCKLEN + 1];
    char iucr [IUCRLEN + 1];
    char type[TYPELEN + 1];
    char desc[DESCLEN + 1];
    char location_desc[LOC_DESC_LEN + 1];
    bool arrest;
    bool domestic;
    char beat[BEATLEN + 1];
    char district[DISTRICTLEN + 1];
    char ward[WARDLEN + 1];
    char comm_area[COMM_AREA_LEN + 1];
    char fbi_code[FBI_CODE_LEN + 1];
} typedef record;

enum record_type{
    R_ID, R_CASE, R_DATE, R_BLOCK, R_IUCR, R_TYPE, R_DESC, R_LOCATION, R_ARREST, R_DOMESTIC, R_BEAT, R_DISTRICT, R_WARD, R_COMM_AREA, R_FBI_CODE, R_INVALID
};



#endif /* record_h */
