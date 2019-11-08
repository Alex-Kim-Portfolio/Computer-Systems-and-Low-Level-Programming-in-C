//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Returns 1 is suff is a suffix of s ignoring case or 0 otherwise .*/

int ends_with_ignore_case(char *s, char *suff) {
    int stringLength = 0;
    int suffLength = 0;
    char *ptr1 = s;
    char *ptr2 = suff;
    int result = 1;
    
    while(*ptr1 != '\0') {
        stringLength++;
        ptr1++;
    }
    
    while(*ptr2 != '\0') {
        suffLength++;
        ptr2++;
    }
    
    for(int i = suffLength; i > 0; --i) {
        ptr1--;
        ptr2--;

        if(tolower(*ptr1) != tolower(*ptr2)) {
            result = 0;
            break;
        }
    }
    
    return result;
}
