//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Compares s1 and s2 ignoring case. Returns a positive number if s1 would appear after s2 in the dictionary, a negative number if it would appear before s2, or 0 if the two are equal. */

int strcmp_ign_case(char *s1, char *s2) {
    int stringLength1 = 0;
    int stringLength2 = 0;
    int result = 0;
 
    char *ptr1 = s1;
    char *ptr2 = s2;
 
    while(*ptr1 != '\0') {
        stringLength1++;
        ptr1++;
    }
 
    while(*ptr2 != '\0') {
         stringLength2++;
         ptr2++;
    }
 
    char stringCopy1[sizeof(char) * stringLength1];
    char stringCopy2[sizeof(char) * stringLength2];
 
    for(int i = 0; i < stringLength1; ++i) {
        stringCopy1[i] = s1[i];
    }
 
    for(int i = 0; i < stringLength2; ++i) {
        stringCopy2[i] = s2[i];
    }
 
    ptr1 = stringCopy1;
    ptr2 = stringCopy2;
 
    while((*ptr1 != '\0') && (*ptr2 != '\0')) {
        if(tolower(*ptr1) == tolower(*ptr2)) {
            ptr1++;
            ptr2++;
            continue;
        } else if(tolower(*ptr1) > tolower(*ptr2)) {
            result = 1;
            break;
        } else if(tolower(*ptr1) < tolower(*ptr2)) {
            result = -1;
            break;
        }
    }
 
    return result;
}
