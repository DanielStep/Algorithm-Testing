//
//  utilities.c
//   
//
//  Created by Daniel Stepanenko on 13/04/2016.
//   
//

#include <stdio.h>
#include "utilities.h"

FILE * gropen(const char * fname, const char* operation)
{
    FILE * fp;
    if((fp = fopen(fname, operation)) == NULL)
    {
        perror("failed to open file");
        exit(1);
    }
    return fp;
}

int compileRegex(const char *pattern, regex_t *re){
    
    int compileStatus;
    
    compileStatus = regcomp(re, pattern, 0);
    if (compileStatus != 0) {
        
        /* Report error if 0 */
        return(compileStatus);
    }else{
        return 0;
    }
}

int matchRegex(char *string, regex_t re){
    
    int    status;
    size_t     nmatch = 1;
    regmatch_t pmatch[1];
    
    //regexec() returns 0 if matching found
    status = regexec(&re, string, nmatch, pmatch, 0);
    
    //regfree(&re);
    
    if (status == 0) {
        return 0;
    }
    else {
        return(status);
    }
}
