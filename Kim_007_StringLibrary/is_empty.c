//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Returns 1 if s is NULL, consists of only the null character (""), or only whitespace. Returns 0 otherwise.*/

int is_empty(char *s) {
    int result = 0;
    char *ptr = s;
    
    if(s == NULL) {
        result = 1;
    } else if (*ptr == '\0') {
        result = 1;
    } else {
        while(*ptr != '\0') {
            if (*ptr == ' ') {
                result = 1;
            } else {
                result = 0;
                break;
            }
            
            ptr++;
        }
    }
    
    return result;
}
