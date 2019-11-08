//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Returns a string consisting of the first n strings in strs with the character c used as a separator.*/

char *str_connect(char **strs, int n, char c) {
    int stringLength = 0;
    int numOfSeps = n - 1;

    char *ptr = strs;

    while(*ptr != '\0') {
        stringLength++;
        ptr++;
    }

    char *resultString = malloc(sizeof(char) * (stringLength + numOfSeps) + 1);
    ptr = strs;
    char *ptr2 = resultString;

    while(*ptr != '\0') {
        if(*ptr == ' ') {
            if(numOfSeps != 0) {
                *ptr2 = c;
                numOfSeps--;
            }
            ptr++;
            ptr2++;
        } else {
            *ptr2 = *ptr;
            ptr++;
            ptr2++;
        }
    }

    *ptr2 = '\0';
    
    return resultString;
}
