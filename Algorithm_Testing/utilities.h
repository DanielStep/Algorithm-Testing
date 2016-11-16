//
//  utilities.h
//   
//
//  Created by Daniel Stepanenko on 13/04/2016.
//   
//

#ifndef utilities_h
#define utilities_h

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <regex.h>



FILE * gropen(const char * fname, const char* operation);
int compileRegex(const char *pattern, regex_t *re);
int matchRegex(char *string, regex_t re);

#endif /* utilities_h */
