//
//  main.c
//   
//
//  Created by Daniel Stepanenko on 12/04/2016.
//   
//

#include "query_main.h"

int main(int argc, const char * argv[]) {
    
    /* validate command line arguments */
    if(argc != NUMARGS)
    {
        fprintf(stderr, "Invalid arguments.\n\n");
        return EXIT_FAILURE;
    }
    
    FILE *fpUnsortedHeap = openFile(argv[1]); //unsorted
    FILE *fpHeapSortedIUCR = openFile(argv[2]); //sorted
    FILE *fpHeapSortedID = openFile(argv[3]); //sorted
    FILE *fpHashIUCR = openFile(argv[4]); //hash of sorted
    FILE *fpHashID = openFile(argv[5]); //hash of sorted

    
    heapQuery1(fpUnsortedHeap);
    heapQuery2(fpUnsortedHeap);
    heapQuery3(fpUnsortedHeap);
    heapQuery4(fpUnsortedHeap);
    heapQuery5(fpUnsortedHeap);
    
    heapQuery6(fpUnsortedHeap);
    heapQuery7(fpUnsortedHeap);
    heapQuery8(fpUnsortedHeap);
    heapQuery9(fpUnsortedHeap);
    
    sortedQuery1(fpHeapSortedIUCR);
    sortedQuery2(fpHeapSortedID);
    sortedQuery3(fpHeapSortedID);
    sortedQuery4(fpHeapSortedIUCR);
    
    hashQuery1(fpHashIUCR, fpHeapSortedIUCR);
    hashQuery2(fpHashID, fpHeapSortedID);
    hashQuery3(fpHashID, fpHeapSortedID);
    hashQuery4(fpHashIUCR, fpHeapSortedIUCR);

}
