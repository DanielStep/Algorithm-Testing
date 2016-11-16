//
//  hash.c
//
//  Created by Daniel Stepanenko on 4/05/2016.
//   
//

#include "hash.h"



size_t hash_rids_per_page(size_t pagesize, size_t rid_size) {
    size_t usable_space = pagesize - sizeof(struct hash_page);
    double num_rids = usable_space / (double) rid_size;
    return (size_t)floor(num_rids);
}




