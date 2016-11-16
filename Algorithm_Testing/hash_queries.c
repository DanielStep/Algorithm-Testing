//
//  hash_queries.c
//
//  Created by Daniel Stepanenko on 21/05/2016.
//

#include "hash_queries.h"

void hashQuery1(FILE *fpHash, FILE *fpHeap){
    
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    
    struct hash_header * header;
    size_t hash_page_size;
    int ret_val_vbuf;
    struct hash_page * hashPage;
    unsigned long hashnum;
    struct rid *currentRid;
    struct record heapRecord;
    regex_t theftRegex;
    regex_t locationRegex;
    int matchCount;
    struct heap_offset heapOffset;
    file_offset_t heapFileOffset;
    page_offset_t heapPageOffset;
    file_offset_t hashFileOffset;
    file_offset_t hashOverflowOffset;
    
    fseek(fpHash, 0, SEEK_SET);
    header = malloc(sizeof(struct hash_header));
    fread(header, sizeof(char), sizeof(struct hash_header), fpHash);
    hash_page_size = header->page_size;
    ret_val_vbuf = setvbuf(fpHash, NULL, _IONBF, header->page_size);
    
    hashPage = malloc(hash_page_size);
    
    byte key[34] = {'0', '8', '1', '0'};
    hashnum = sdbm_hash(key, header->size_field);
    
    unsigned long bucketOffset = hashnum % header->num_pages;
    currentRid = malloc(sizeof(struct rid));
    
    compileRegex("0810", &theftRegex);
    compileRegex("STREET", &locationRegex);
    matchCount = 0;
    
    //find first bucket
    hashFileOffset = sizeof(struct hash_header) + (bucketOffset * header->page_size);
    fseek(fpHash, hashFileOffset, SEEK_SET);
    fread(hashPage, sizeof(char), hash_page_size, fpHash);
    for(int i = 0; i < hashPage->num_rids; i++){
        memcpy(currentRid, hashPage->data + rid_size(header->size_field) * i, rid_size(header->size_field));
        
        if (strcmp(currentRid->key, "0810") == 0){
            
            heapOffset = currentRid->offset;
            heapFileOffset = heapOffset.file_offset;
            heapPageOffset = heapOffset.page_offset;
            
            heapRecord = seekHeapRid(heapFileOffset, heapPageOffset, fpHeap);
            
            if (matchRegex(heapRecord.location_desc, locationRegex) == 0){
                matchCount++;
            }
        }
    }
    //Find overflow buckets
    while (hashPage->overflow != 0){
        hashOverflowOffset = hashPage->overflow;
        fseek(fpHash, hashOverflowOffset, SEEK_SET);
        fread(hashPage, sizeof(char), hash_page_size, fpHash);
        for(int i = 0; i < hashPage->num_rids; i++){
            memcpy(currentRid, hashPage->data + rid_size(header->size_field) * i, rid_size(header->size_field));
            
            if (strcmp(currentRid->key, "0810") == 0){
                
                heapOffset = currentRid->offset;
                heapFileOffset = heapOffset.file_offset;
                heapPageOffset = heapOffset.page_offset;
                
                heapRecord = seekHeapRid(heapFileOffset, heapPageOffset, fpHeap);
                if (matchRegex(heapRecord.location_desc, locationRegex) == 0){
                    matchCount++;
                }
            }
        }
    }
    printf("hashQuery1: %d matches found\n", matchCount);
    struct timeval tv_end;
    gettimeofday(&tv_end, NULL);
    unsigned long duration = tv_end.tv_sec - tv_start.tv_sec;
    printf("hashQuery1 run time: %lu seconds\n", duration);
}


void hashQuery2(FILE *fpHash, FILE *fpHeap){
    
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    
    struct hash_header * header;
    size_t hash_page_size;
    int ret_val_vbuf;
    struct hash_page * hashPage;
    unsigned long hashnum;
    struct rid *currentRid;
    struct record heapRecord;
    regex_t idRegex;
    int matchCount;
    struct heap_offset heapOffset;
    file_offset_t heapFileOffset;
    page_offset_t heapPageOffset;
    file_offset_t hashFileOffset;
    
    fseek(fpHash, 0, SEEK_SET);
    header = malloc(sizeof(struct hash_header));
    fread(header, sizeof(char), sizeof(struct hash_header), fpHash);
    hash_page_size = header->page_size;
    ret_val_vbuf = setvbuf(fpHash, NULL, _IONBF, header->page_size);
    
    hashPage = malloc(hash_page_size);
    
    byte key[34] = {'9', '9', '9', '9', '9', '5', '2'};
    hashnum = sdbm_hash(key, header->size_field);
    
    unsigned long bucketOffset = hashnum % header->num_pages;
    currentRid = malloc(sizeof(struct rid));
    
    compileRegex("9999952", &idRegex);
    matchCount = 0;
    
    //find first bucket
    hashFileOffset = sizeof(struct hash_header) + (bucketOffset * header->page_size);
    fseek(fpHash, hashFileOffset, SEEK_SET);
    fread(hashPage, sizeof(char), hash_page_size, fpHash);
    for(int i = 0; i < hashPage->num_rids; i++){
        memcpy(currentRid, hashPage->data + rid_size(header->size_field) * i, rid_size(header->size_field));
        
        if (strcmp(currentRid->key, "9999952") == 0){
            
            heapOffset = currentRid->offset;
            heapFileOffset = heapOffset.file_offset;
            heapPageOffset = heapOffset.page_offset;
            
            heapRecord = seekHeapRid(heapFileOffset, heapPageOffset, fpHeap);
            
            if (matchRegex(heapRecord.id, idRegex) == 0){
                matchCount++;
            }
        }
    }
    printf("hashQuery2: %d matches found\n", matchCount);
    struct timeval tv_end;
    gettimeofday(&tv_end, NULL);
    unsigned long duration = tv_end.tv_sec - tv_start.tv_sec;
    printf("hashQuery2 run time: %lu seconds\n", duration);
}


void hashQuery3(FILE *fpHash, FILE *fpHeap){
    
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    
    struct hash_header * header;
    size_t hash_page_size;
    int ret_val_vbuf;
    struct hash_page * hashPage;
    unsigned long hashnum;
    struct rid *currentRid;
    struct record heapRecord;
    regex_t idRegex;
    int matchCount;
    struct heap_offset heapOffset;
    file_offset_t heapFileOffset;
    page_offset_t heapPageOffset;
    file_offset_t hashFileOffset;
    
    fseek(fpHash, 0, SEEK_SET);
    header = malloc(sizeof(struct hash_header));
    fread(header, sizeof(char), sizeof(struct hash_header), fpHash);
    hash_page_size = header->page_size;
    ret_val_vbuf = setvbuf(fpHash, NULL, _IONBF, header->page_size);
    
    hashPage = malloc(hash_page_size);
    
    byte key[34] = {'1', '3', '0', '9', '8', '8', '1'};
    hashnum = sdbm_hash(key, header->size_field);
    
    unsigned long bucketOffset = hashnum % header->num_pages;
    currentRid = malloc(sizeof(struct rid));
    
    compileRegex("1309881", &idRegex);
    matchCount = 0;
    
    //find first bucket
    hashFileOffset = sizeof(struct hash_header) + (bucketOffset * header->page_size);
    fseek(fpHash, hashFileOffset, SEEK_SET);
    fread(hashPage, sizeof(char), hash_page_size, fpHash);
    for(int i = 0; i < hashPage->num_rids; i++){
        memcpy(currentRid, hashPage->data + rid_size(header->size_field) * i, rid_size(header->size_field));
        
        if (strcmp(currentRid->key, "1309881") == 0){
            
            heapOffset = currentRid->offset;
            heapFileOffset = heapOffset.file_offset;
            heapPageOffset = heapOffset.page_offset;
            
            heapRecord = seekHeapRid(heapFileOffset, heapPageOffset, fpHeap);
            
            if (matchRegex(heapRecord.id, idRegex) == 0){
                matchCount++;
            }
        }
    }
    printf("hashQuery3: %d matches found\n", matchCount);
    struct timeval tv_end;
    gettimeofday(&tv_end, NULL);
    unsigned long duration = tv_end.tv_sec - tv_start.tv_sec;
    printf("hashQuery3 run time: %lu seconds\n", duration);
}


void hashQuery4(FILE *fpHash, FILE *fpHeap){
    
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    
    struct hash_header * header;
    size_t hash_page_size;
    int ret_val_vbuf;
    struct hash_page * hashPage;
    unsigned long hashnum;
    struct rid *currentRid;
    struct record heapRecord;
    int matchCount;
    struct heap_offset heapOffset;
    file_offset_t heapFileOffset;
    page_offset_t heapPageOffset;
    file_offset_t hashFileOffset;
    file_offset_t hashOverflowOffset;
    
    fseek(fpHash, 0, SEEK_SET);
    header = malloc(sizeof(struct hash_header));
    fread(header, sizeof(char), sizeof(struct hash_header), fpHash);
    hash_page_size = header->page_size;
    ret_val_vbuf = setvbuf(fpHash, NULL, _IONBF, header->page_size);
    
    hashPage = malloc(hash_page_size);
    
    byte key[34] = {'0', '8', '2', '0'};
    hashnum = sdbm_hash(key, header->size_field);
    
    unsigned long bucketOffset = hashnum % header->num_pages;
    currentRid = malloc(sizeof(struct rid));
    
    regex_t theftRegex;
    compileRegex("0820", &theftRegex);
    regex_t streetRegex;
    compileRegex("STREET", &streetRegex);
    regex_t autoRegex;
    compileRegex("^AUTO$", &autoRegex);
    regex_t truckRegex;
    compileRegex("TRUCK", &truckRegex);
    regex_t vehicleRegex;
    compileRegex("VEHICLE", &vehicleRegex);
    regex_t trainRegex;
    compileRegex("TRAIN$", &trainRegex);
    regex_t taxiRegex;
    compileRegex("TAXI", &taxiRegex);
    regex_t busRegex;
    compileRegex("BUS$", &busRegex);
    regex_t transportationRegex;
    compileRegex("TRANSPORTATION$", &transportationRegex);
    regex_t aircraftRegex;
    compileRegex("AIRCRAFT", &aircraftRegex);
    regex_t hospitalRegex;
    compileRegex("^HOSPITAL BUILDING/GROUNDS$", &hospitalRegex);
    regex_t restRegex;
    compileRegex("^RESTAURANT$", &restRegex);
    regex_t apartmentRegex;
    compileRegex("^APARTMENT$", &apartmentRegex);
    regex_t departmentRegex;
    compileRegex("^DEPARTMENT$", &departmentRegex);
    regex_t sportRegex;
    compileRegex("^SPORTS ARENA/STADIUM$", &sportRegex);
    regex_t sidewalkRegex;
    compileRegex("SIDEWALK", &sidewalkRegex);
    regex_t alleyRegex;
    compileRegex("ALLEY", &alleyRegex);
    regex_t groceryRegex;
    compileRegex("GROCERY FOOD STORE", &groceryRegex);
    regex_t convenienceRegex;
    compileRegex("CONVENIENCE STORE", &convenienceRegex);
    regex_t retailRegex;
    compileRegex("SMALL RETAIL STORE", &retailRegex);
    regex_t churchRegex;
    compileRegex("CHURCH", &churchRegex);
    
    matchCount = 0;
    
    //find first bucket
    hashFileOffset = sizeof(struct hash_header) + (bucketOffset * header->page_size);
    fseek(fpHash, hashFileOffset, SEEK_SET);
    fread(hashPage, sizeof(char), hash_page_size, fpHash);
    for(int i = 0; i < hashPage->num_rids; i++){
        memcpy(currentRid, hashPage->data + rid_size(header->size_field) * i, rid_size(header->size_field));
        
        if (strcmp(currentRid->key, "0820") == 0){
            
            heapOffset = currentRid->offset;
            heapFileOffset = heapOffset.file_offset;
            heapPageOffset = heapOffset.page_offset;
            
            heapRecord = seekHeapRid(heapFileOffset, heapPageOffset, fpHeap);
            
            if (matchRegex(heapRecord.iucr, theftRegex) == 0){
                if (matchRegex(heapRecord.location_desc, streetRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, autoRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, truckRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, vehicleRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, trainRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, apartmentRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, departmentRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, sportRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, sidewalkRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, alleyRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, groceryRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, convenienceRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, retailRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, churchRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, taxiRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, busRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, transportationRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, aircraftRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, hospitalRegex) == 0){
                    matchCount++;
                } else if(matchRegex(heapRecord.location_desc, restRegex) == 0){
                    matchCount++;
                }
            }
        }
    }
    while (hashPage->overflow != 0){
        hashOverflowOffset = hashPage->overflow;
        fseek(fpHash, hashOverflowOffset, SEEK_SET);
        fread(hashPage, sizeof(char), hash_page_size, fpHash);
        for(int i = 0; i < hashPage->num_rids; i++){
            memcpy(currentRid, hashPage->data + rid_size(header->size_field) * i, rid_size(header->size_field));
            
            if (strcmp(currentRid->key, "0820") == 0){
                
                heapOffset = currentRid->offset;
                heapFileOffset = heapOffset.file_offset;
                heapPageOffset = heapOffset.page_offset;
                
                heapRecord = seekHeapRid(heapFileOffset, heapPageOffset, fpHeap);
                if (matchRegex(heapRecord.iucr, theftRegex) == 0){
                    if (matchRegex(heapRecord.location_desc, streetRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, autoRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, truckRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, vehicleRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, trainRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, apartmentRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, departmentRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, sportRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, sidewalkRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, alleyRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, groceryRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, convenienceRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, retailRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, churchRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, taxiRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, busRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, transportationRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, aircraftRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, hospitalRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(heapRecord.location_desc, restRegex) == 0){
                        matchCount++;
                    }
                }
            }
        }
    }
    
    printf("hashQuery4: %d matches found\n", matchCount);
    struct timeval tv_end;
    gettimeofday(&tv_end, NULL);
    unsigned long duration = tv_end.tv_sec - tv_start.tv_sec;
    printf("hashQuery4 run time: %lu seconds\n", duration);
}


unsigned long sdbm_hash(const byte * data, size_t len) {
    unsigned long hash = 0;
    size_t count;
    for(count = 0; count < len; ++count)
        hash = data[count] + (hash << 6) + (hash << 16) - hash;
    return hash;
}

struct record seekHeapRid(file_offset_t fileOffset, page_offset_t pageOffset, FILE *fpHeap){
    
    fseek(fpHeap, 0, SEEK_SET);
    
    struct heap_header * header = malloc(sizeof(struct heap_header));
    fread(header, sizeof(char), sizeof(struct heap_header), fpHeap);
    
    size_t page_size = header->page_size;
    
    int ret_val_vbuf;
    ret_val_vbuf = setvbuf(fpHeap, NULL, _IONBF, header->page_size);
    
    struct heap_page * page = malloc(page_size);
    struct record record;
    
    fseek(fpHeap, fileOffset, SEEK_SET);
    
    fread(page, sizeof(char), page_size, fpHeap);
    
    record = page->records[pageOffset];
    
    free(page);
    free(header);
    
    return record;
}

size_t rid_size(size_t key_size)
{
    return key_size + sizeof (struct rid);
}
