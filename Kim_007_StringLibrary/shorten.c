//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Shortens the string s to new_len. If the original length of s is less than or equal to new_len, s is unchanged.*/

void shorten(char *s, int new_len) {
    int stringLength = 0;
    char *ptr = s;
     
    while(*ptr != '\0') {
        stringLength++;
        ptr++;
    }
    
    char stringCopy[new_len];
     
    if(stringLength > new_len) {
        for(int i = 0; i < new_len; ++i) {
            stringCopy[i] = s[i];
        }
        
        printf("%s\n", stringCopy);
    } else {
        printf("%s\n", s);
    }
}
