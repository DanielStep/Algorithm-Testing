//
//  heap_page.h
//   
//
//  Created by Daniel Stepanenko on 18/04/2016.
//   
//

#ifndef heap_page_h
#define heap_page_h

#include <stdio.h>
#include <stdbool.h>
#include "record.h"

typedef size_t file_offset_t;
typedef size_t page_offset_t;

struct heap_header {
    size_t total_pages;
    size_t records_per_page;
    size_t page_size;
    size_t total_records;
    size_t size_record;
};

struct heap_page {
    size_t num_records;
    struct record records[];
};





#endif /* heap_page_h */
