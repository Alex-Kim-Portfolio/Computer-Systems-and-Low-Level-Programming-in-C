//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include "alex_kim_string_library.h"

/* Returns the number of characters c in s1such that b <= c <= t.*/

int num_in_range(char *s1, char b, char t) {
    int countOfNumInRange = 0;
    int stringLength = 0;
    char *ptr = s1;
    
    while(*ptr != '\0') {
        stringLength++;
        ptr++;
    }
    
    char stringCopy[stringLength];
    
    for(int i = 0; i < stringLength; ++i) {
        stringCopy[i] = s1[i];
    }
    
    for(int i = 0; i < stringLength; ++i) {
        if((stringCopy[i] >= b) && (stringCopy[i] <= t)){
            countOfNumInRange++;
        }
    }
    
    return countOfNumInRange;
}

