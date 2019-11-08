//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Returns length of s1 - length of s2.*/

int len_diff(char *s1, char *s2) {
    char *ptr1 = s1;
    int stringLength1 = 0;
    char *ptr2 = s2;
    int stringLength2 = 0;
    int lengthDiff = 0;

    while(*ptr1 != '\0') {
        stringLength1++;
        ptr1++;
    }
    
    while(*ptr2 != '\0') {
        stringLength2++;
        ptr2++;
    }
    
    lengthDiff = stringLength1 - stringLength2;
        
    return lengthDiff;
}
