//
//  queries.h
//   
//
//  Created by Daniel Stepanenko on 13/04/2016.
//   
//

#ifndef queries_h
#define queries_h
#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

#if __STDC_VERSION__ >= 199901L
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE 500
#endif /* __STDC_VERSION__ */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include "utilities.h"
#include "heap_page.h"
#include "hash.h"
#include <math.h>


FILE *openFile(const char * inputFile);
void heapQuery1(FILE *fpHeap);
void heapQuery2(FILE *fpHeap);
void heapQuery3(FILE *fpHeap);
void heapQuery4(FILE *fpHeap);
void heapQuery5(FILE *fpHeap);

struct month {
    int monthNum;
    int count;
};

struct year {
    int yearNum;
    int count;
};
#endif /* queries_h */
