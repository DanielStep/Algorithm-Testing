//
//  unsorted_queries.c
//   
//
//  Created by Daniel Stepanenko on 21/05/2016.
//   
//

#include "unsorted_queries.h"

void heapQuery6(FILE *fpHeap){
    
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    
    fseek(fpHeap, 0, SEEK_SET);
    
    struct heap_header * header = malloc(sizeof(struct heap_header));
    fread(header, sizeof(char), sizeof(struct heap_header), fpHeap);
    
    int ret_val_vbuf;
    ret_val_vbuf = setvbuf(fpHeap, NULL, _IONBF, header->page_size);
    
    size_t page_size = header->page_size;
    size_t record_size = header->size_record;
    
    struct heap_page * page = malloc(page_size);
    struct record * record = malloc(record_size);
    
    regex_t theftRegex;
    compileRegex("0810", &theftRegex);
    regex_t locationRegex;
    compileRegex("STREET", &locationRegex);
    
    int matchCount = 0;
    while(fread(page, sizeof(char), page_size, fpHeap) == page_size){
        
        for (int i = 0; i < page->num_records; i++) {
            record = &page->records[i];
            
            if (matchRegex(record->iucr, theftRegex) == 0){
                if (matchRegex(record->location_desc, locationRegex) == 0){
                    matchCount++;
                }
            }
        }
    }
    printf("unsortedQuery1: %d matches found\n", matchCount);
    
    free(header);
    free(page);
    
    struct timeval tv_end;
    gettimeofday(&tv_end, NULL);
    unsigned long duration = tv_end.tv_sec - tv_start.tv_sec;
    printf("unsortedQuery1 run time: %lu seconds\n", duration);
}

void heapQuery7(FILE *fpHeap){
    
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    
    fseek(fpHeap, 0, SEEK_SET);
    
    struct heap_header * header = malloc(sizeof(struct heap_header));
    fread(header, sizeof(char), sizeof(struct heap_header), fpHeap);
    
    int ret_val_vbuf;
    ret_val_vbuf = setvbuf(fpHeap, NULL, _IONBF, header->page_size);
    
    size_t page_size = header->page_size;
    size_t record_size = header->size_record;
    
    struct heap_page * page = malloc(page_size);
    struct record * record = malloc(record_size);
    
    regex_t idRegex;
    compileRegex("9999952", &idRegex);
    
    
    int matchCount = 0;
    while(fread(page, sizeof(char), page_size, fpHeap) == page_size){
        
        for (int i = 0; i < page->num_records; i++) {
            record = &page->records[i];
            
            if (matchRegex(record->id, idRegex) == 0){
                matchCount++;
            }
        }
    }
    printf("unsortedQuery2: %d matches found\n", matchCount);
    
    free(header);
    free(page);
    
    struct timeval tv_end;
    gettimeofday(&tv_end, NULL);
    unsigned long duration = tv_end.tv_sec - tv_start.tv_sec;
    printf("unsortedQuery2 run time: %lu seconds\n", duration);
}

void heapQuery8(FILE *fpHeap){
    
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    
    fseek(fpHeap, 0, SEEK_SET);
    
    struct heap_header * header = malloc(sizeof(struct heap_header));
    fread(header, sizeof(char), sizeof(struct heap_header), fpHeap);
    
    int ret_val_vbuf;
    ret_val_vbuf = setvbuf(fpHeap, NULL, _IONBF, header->page_size);
    
    size_t page_size = header->page_size;
    size_t record_size = header->size_record;
    
    struct heap_page * page = malloc(page_size);
    struct record * record = malloc(record_size);
    
    regex_t idRegex;
    compileRegex("1309881", &idRegex);
    
    
    int matchCount = 0;
    while(fread(page, sizeof(char), page_size, fpHeap) == page_size){
        
        for (int i = 0; i < page->num_records; i++) {
            record = &page->records[i];
            
            if (matchRegex(record->id, idRegex) == 0){
                matchCount++;
            }
        }
    }
    printf("unsortedQuery3: %d matches found\n", matchCount);
    
    free(header);
    free(page);
    
    struct timeval tv_end;
    gettimeofday(&tv_end, NULL);
    unsigned long duration = tv_end.tv_sec - tv_start.tv_sec;
    printf("unsortedQuery3 run time: %lu seconds\n", duration);
}

void heapQuery9(FILE *fpHeap){
    
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    
    fseek(fpHeap, 0, SEEK_SET);
    
    struct heap_header * header = malloc(sizeof(struct heap_header));
    fread(header, sizeof(char), sizeof(struct heap_header), fpHeap);
    
    int ret_val_vbuf;
    ret_val_vbuf = setvbuf(fpHeap, NULL, _IONBF, header->page_size);
    
    size_t page_size = header->page_size;
    size_t record_size = header->size_record;
    
    struct heap_page * page = malloc(page_size);
    struct record * record = malloc(record_size);
    
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
    
    int matchCount = 0;
    while(fread(page, sizeof(char), page_size, fpHeap) == page_size){
        
        for (int i = 0; i < page->num_records; i++) {
            record = &page->records[i];
            
            if (matchRegex(record->iucr, theftRegex) == 0){
                if (matchRegex(record->location_desc, streetRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, autoRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, truckRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, vehicleRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, trainRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, apartmentRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, departmentRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, sportRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, sidewalkRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, alleyRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, groceryRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, convenienceRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, retailRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, churchRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, taxiRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, busRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, transportationRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, aircraftRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, hospitalRegex) == 0){
                    matchCount++;
                } else if(matchRegex(record->location_desc, restRegex) == 0){
                    matchCount++;
                }
            }
        }
    }
    printf("unsortedQuery4: %d matches found\n", matchCount);
    
    free(header);
    free(page);
    
    struct timeval tv_end;
    gettimeofday(&tv_end, NULL);
    unsigned long duration = tv_end.tv_sec - tv_start.tv_sec;
    printf("unsortedQuery4 run time: %lu seconds\n", duration);
}
