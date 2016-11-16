//
//  queries.c
//   
//
//  Created by Daniel Stepanenko on 13/04/2016.
//   
//

//Original Unsorted Heap queries based on queries required in Assignment 1, before requirements of Assignment 2 changed.

#include "queries.h"

FILE *openFile(const char * inputFile){

    int ret_val_vbuf;
    FILE *fp;
    
    fp = gropen(inputFile, "r");
    
    ret_val_vbuf = setvbuf(fp, NULL, _IONBF, 0);

    return fp;
}

void heapQuery1(FILE *fpHeap){
    
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    
    fseek(fpHeap, 0, SEEK_SET);
    
    struct heap_header * header = malloc(sizeof(struct heap_header));
    fread(header, sizeof(char), sizeof(struct heap_header), fpHeap);
    
    size_t page_size = header->page_size;
    size_t record_size = header->size_record;
    
    int ret_val_vbuf;
    ret_val_vbuf = setvbuf(fpHeap, NULL, _IONBF, header->page_size);
    
    struct heap_page * page = malloc(page_size);
    struct record * record = malloc(record_size);
    
    regex_t robberyRegex;
    compileRegex("^ROBBERY$", &robberyRegex);
    regex_t gunRegex;
    compileRegex("GUN", &gunRegex);
    regex_t residenceRegex;
    compileRegex("RESIDENCE", &residenceRegex);
    regex_t houseRegex;
    compileRegex("^HOUSE%", &houseRegex);
    regex_t apartementRegex;
    compileRegex("^APARTMENT$", &apartementRegex);
    
    int matchCount = 0;
    while(fread(page, sizeof(char), page_size, fpHeap) == page_size){
        
        for (int i = 0; i < page->num_records; i++) {
            record = &page->records[i];
            
            if (matchRegex(record->type, robberyRegex) == 0){
                if (matchRegex(record->desc, gunRegex) == 0) {
                    if (matchRegex(record->location_desc, residenceRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(record->location_desc, houseRegex) == 0){
                        matchCount++;
                    } else if(matchRegex(record->location_desc, apartementRegex) == 0){
                        matchCount++;
                    }
                }
            }
            
        }
    }
    printf("heapQuery1: %d matches found\n", matchCount);
    
    free(header);
    free(page);
    
    struct timeval tv_end;
    gettimeofday(&tv_end, NULL);
    unsigned long duration = tv_end.tv_sec - tv_start.tv_sec;
    printf("heapQuery1 run time: %lu seconds\n", duration);

}


void heapQuery2(FILE *fpHeap){
    
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    
    fseek(fpHeap, 0, SEEK_SET);
    
    struct heap_header * header = malloc(sizeof(struct heap_header));
    fread(header, sizeof(char), sizeof(struct heap_header), fpHeap);
    
    int ret_val_vbuf;
    ret_val_vbuf = setvbuf(fpHeap, NULL, _IONBF, header->page_size);
    
    size_t page_size = header->page_size;
    size_t record_size = header->size_record;
    
    regex_t motor_vehicle_theftRegex;
    compileRegex("^MOTOR VEHICLE THEFT$", &motor_vehicle_theftRegex);
    regex_t planeRegex;
    compileRegex("PLANE", &planeRegex);
    regex_t vehRegex;
    compileRegex("VEH", &vehRegex);
    regex_t nonvehRegex;
    compileRegex("^THEFT BY LESSEE,NON-VEH$", &nonvehRegex);
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
    

    struct heap_page * page = malloc(page_size);
    struct record * record = malloc(record_size);
    
    int matchCount = 0;
    while(fread(page, sizeof(char), page_size, fpHeap) == page_size){
        
        for (int i = 0; i < page->num_records; i++) {
            record = &page->records[i];
            
            if(matchRegex(record->type, motor_vehicle_theftRegex) == 0){
                matchCount++;
            } else if(matchRegex(record->desc, planeRegex) == 0){
                matchCount++;
            } else if(matchRegex(record->desc, vehRegex) == 0 && matchRegex(record->desc, nonvehRegex) == 0){
                matchCount++;
            } else if(matchRegex(record->location_desc, autoRegex) == 0){
                matchCount++;
            } else if(matchRegex(record->location_desc, truckRegex) == 0){
                matchCount++;
            } else if(matchRegex(record->location_desc, vehicleRegex) == 0){
                matchCount++;
            } else if(matchRegex(record->location_desc, trainRegex) == 0){
                matchCount++;
            } else if(matchRegex(record->location_desc, taxiRegex) == 0){
                matchCount++;
            } else if(matchRegex(record->location_desc, busRegex) == 0){
                matchCount++;
            } else if(matchRegex(record->location_desc, transportationRegex) == 0){
                matchCount++;
            } else if(matchRegex(record->location_desc, aircraftRegex) == 0){
                matchCount++;
            }
        }
    }
    printf("heapQuery2: %d matches found\n", matchCount);
    
    free(header);
    free(page);
    
    struct timeval tv_end;
    gettimeofday(&tv_end, NULL);
    unsigned long duration = tv_end.tv_sec - tv_start.tv_sec;
    printf("heapQuery2 run time: %lu seconds\n", duration);
}

void heapQuery3(FILE *fpHeap){
    
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
    
    regex_t narcoticsRegex;
    compileRegex("NARCOTICS", &narcoticsRegex);
    regex_t federalRegex;
    compileRegex("FEDERAL BUILDING", &federalRegex);
    regex_t govRegex;
    compileRegex("GOVERNMENT BUILDING/PROPERTY", &govRegex);
    
    
    int matchCount = 0;
    while(fread(page, sizeof(char), page_size, fpHeap) == page_size){
        
        for (int i = 0; i < page->num_records; i++) {
            record = &page->records[i];
            
            if (matchRegex(record->type, narcoticsRegex) == 0){
                if (matchRegex(record->location_desc, federalRegex) == 0){
                    matchCount++;
                } else if (matchRegex(record->location_desc, govRegex) == 0){
                    matchCount++;
                }
            }
        }
    }
    printf("heapQuery3: %d matches found\n", matchCount);
    
    free(header);
    free(page);
    
    struct timeval tv_end;
    gettimeofday(&tv_end, NULL);
    unsigned long duration = tv_end.tv_sec - tv_start.tv_sec;
    printf("heapQuery3 run time: %lu seconds\n", duration);
}

void heapQuery4(FILE *fpHeap){
    
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    
    fseek(fpHeap, 0, SEEK_SET);
    
    struct heap_header * header = malloc(sizeof(struct heap_header));
    fread(header, sizeof(char), sizeof(struct heap_header), fpHeap);
    
    size_t page_size = header->page_size;
    size_t record_size = header->size_record;
    
    struct heap_page * page = malloc(page_size);
    struct record * record = malloc(record_size);
    
    int ret_val_vbuf;
    ret_val_vbuf = setvbuf(fpHeap, NULL, _IONBF, header->page_size);
    
    struct tm *date;
    int yearInt;
    int yearArrayIndex;
    struct year yearArray [17];
    
    for (int i = 0; i < 17; i++) {
        yearArray[i].yearNum = i + 2000;
        yearArray[i].count = 0;
    }
    
    regex_t gunRegex;
    compileRegex("GUN", &gunRegex);
    
    
        while(fread(page, sizeof(char), page_size, fpHeap) == page_size){
        
        for (int i = 0; i < page->num_records; i++) {
            record = &page->records[i];
            
            if (matchRegex(record->desc, gunRegex) == 0) {
                
                date = gmtime(&record->date);
                yearInt = date->tm_year;
                yearArrayIndex = yearInt - 100;
                
                yearArray[yearArrayIndex].count++;
            }
        }
    }

    int largest = yearArray[0].count;
    int indexLargest = 0;
    
    for (int i = 0; i < 17; i++) {
        if (yearArray[i].count > largest) {
            largest = yearArray[i].count;
            indexLargest = i;
        }
    }
    
    printf("heapQuery4: Highest year: %d\n", 2000 + indexLargest);
    
    free(header);
    free(page);
    
    struct timeval tv_end;
    gettimeofday(&tv_end, NULL);
    unsigned long duration = tv_end.tv_sec - tv_start.tv_sec;
    printf("heapQuery4 run time: %lu seconds\n", duration);
}

void heapQuery5(FILE *fpHeap){
    
    struct timeval tv_start;
    gettimeofday(&tv_start, NULL);
    
    fseek(fpHeap, 0, SEEK_SET);
    
    struct heap_header * header = malloc(sizeof(struct heap_header));
    fread(header, sizeof(char), sizeof(struct heap_header), fpHeap);
    
    size_t page_size = header->page_size;
    size_t record_size = header->size_record;
    
    int ret_val_vbuf;
    ret_val_vbuf = setvbuf(fpHeap, NULL, _IONBF, header->page_size);
    
    struct heap_page * page = malloc(page_size);
    struct record * record = malloc(record_size);
    
    struct tm *date;
    int monthInt;
    struct month monthArray [12];
    
    //initialize array of month structs
    for (int i = 0; i < 12; i++) {
        monthArray[i].monthNum = i + 1;
        monthArray[i].count = 0;
    }
    
    while(fread(page, sizeof(char), page_size, fpHeap) == page_size){
        
        for (int i = 0; i < page->num_records; i++) {
            record = &page->records[i];
            
            date = gmtime(&record->date);
            monthInt = date->tm_mon;
            
            monthArray[monthInt].count++;
        }
    }
    
    int largest = monthArray[0].count;
    int indexLargest = 0;
    
    for (int i = 0; i < 12; i++) {
        if (monthArray[i].count > largest) {
            largest = monthArray[i].count;
            indexLargest = i;
        }
    }

    printf("heapQuery5: Highest month: %d\n", indexLargest + 1);
    
    free(header);
    free(page);
    
    struct timeval tv_end;
    gettimeofday(&tv_end, NULL);
    unsigned long duration = tv_end.tv_sec - tv_start.tv_sec;
    printf("heapQuery5 run time: %lu seconds\n", duration);
}


