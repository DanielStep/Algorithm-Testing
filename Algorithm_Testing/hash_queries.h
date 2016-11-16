//
//  hash_queries.h
//
//  Created by Daniel Stepanenko on 21/05/2016.
//   
//

#ifndef hash_queries_h
#define hash_queries_h

#include <stdio.h>
#include "queries.h"


void hashQuery1(FILE *fpHash, FILE *fpHeap);
void hashQuery2(FILE *fpHash, FILE *fpHeap);
void hashQuery3(FILE *fpHash, FILE *fpHeap);
void hashQuery4(FILE *fpHash, FILE *fpHeap);

unsigned long sdbm_hash(const byte * data, size_t len);
struct record seekHeapRid(file_offset_t fileOffset, page_offset_t pageOffset, FILE *fpHeap);
size_t rid_size(size_t key_size);

struct heap_offset {
    file_offset_t file_offset;
    page_offset_t page_offset;
};

struct rid {
    struct heap_offset offset;
    size_t size_key;
    byte key[];
};


#endif /* hash_queries_h */
