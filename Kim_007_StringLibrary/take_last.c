//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Modifies s so that it consists of only its last n characters. If n >= length of s, the original string is unmodified.*/

void take_last(char *s, int n) {
    int stringLength = 0;
    char *ptr = s;
    
    while(*ptr != '\0') {
        stringLength++;
        ptr++;
    }
    
    if(n >= stringLength) {
        printf("%s\n", s);
    } else {
        stringLength = n;
        
        for(int i = n; i > 0; --i) {
            ptr--;
        }
        
        char newString[stringLength];
        
        for(int i = 0; i < stringLength; ++i) {
            newString[i] = *ptr;
            ptr++;
        }
        
        printf("%s\n", newString);
    }
}
