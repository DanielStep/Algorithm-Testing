//
//  hash.h
//   
//
//  Created by Daniel Stepanenko on 4/05/2016.
//   
//

#ifndef hash_h
#define hash_h

#include <stdio.h>
#include <stdbool.h>
#include "record.h"
#include "heap_page.h"
#include <math.h>


#define OCCUPANCY_MULTIPLIER (1.0/0.8)


typedef char byte;

size_t hash_rids_per_page(size_t pagesize, size_t rid_size);


struct hash_header {
    //maximum records per page is fixed as each record will require
    //sizeof(size_t) (for offset) plus sizeof(struct rid) * num_offsets +
    //sizeof(key). Given that we opten for fixed length fields when designing
    //the heap page, we have some simplicity at the cost of disk space.
    size_t max_records;
    //how many records per page?
    size_t max_records_per_page;
    //store the search key so we can easily index into each tuple
    enum record_type index_key;
    //fixed size records ­ how big is each one?
    size_t size_record;
    //field size for a fixed width field
    size_t size_field;
    //this is a static hashed file and as such the number of hash pages is
    //fixed, other than overflow pages. We have tried to minimise overflow
    //pages to some degree by assuming from the get­go that each page will
    // have a mean occupancy of 80%. We round this downwards so that we don't
    //have the problem with small numbers of having 80% rounding up to
    // 100%. If we do have overflow pages they will be located after the
    //static structures that we initialise when we
    //create the file
    size_t num_pages;
    //how big is each page?
    size_t page_size;
};

struct hash_page {
    size_t num_rids;
    size_t page_address;
    file_offset_t overflow;
    byte data[];
};


#endif /* hash_h */
