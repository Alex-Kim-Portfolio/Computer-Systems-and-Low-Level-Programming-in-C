//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Returns a new string consisting of all of the characters of s1 and s2 interleaved with each other.*/

char *str_zip(char *s1, char *s2) {
    char *result = NULL;
    char *ptr1 = s1;
    int stringLength1 = 0;
    char *ptr2 = s2;
    int stringLength2 = 0;
    int shortest = 0;
    int i = 0;
    
    while(*ptr1 != '\0') {
        stringLength1++;
        ptr1++;
    }
    
    while(*ptr2 != '\0') {
        stringLength2++;
        ptr2++;
    }
    
    ptr1 = s1;
    ptr2 = s2;
    
    char stringResult[stringLength1 + stringLength2];
    
    if(stringLength1 < stringLength2) {
        shortest = stringLength1;
        
        for(i; i < (stringLength1 + stringLength2) - 1; ++i) {
            if (i % 2 == 0) {
                stringResult[i] = *ptr1;
                ptr1++;
            } else {
                stringResult[i] = *ptr2;
                ptr2++;
            }
        }
        
        for(i; i < (stringLength1 + stringLength2); ++i) {
            stringResult[i] = *ptr2;
            ptr2++;
        }
    } else if (stringLength2 < stringLength1) {
        shortest = stringLength1;
        
        for(i; i < (stringLength1 + stringLength2) - 1; ++i) {
            if (i % 2 == 0) {
                stringResult[i] = *ptr1;
                ptr1++;
            } else {
                stringResult[i] = *ptr2;
                ptr2++;
            }
        }
               
        for(i; i < (stringLength1 + stringLength2); ++i) {
            stringResult[i] = *ptr1;
            ptr1++;
        }
    } else {
        for(i; i < (stringLength1 + stringLength2); ++i) {
            if (i % 2 == 0) {
                stringResult[i] = *ptr1;
                ptr1++;
            } else {
                stringResult[i] = *ptr2;
                ptr2++;
            }
        }
    }
    
    stringResult[stringLength1 + stringLength2] = '\0';
    
    result = stringResult;
    
    return result;
}
