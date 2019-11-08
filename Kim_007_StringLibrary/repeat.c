//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Returns a new string consisting of the characters in s repeated x times, with the character sep in between. If s is NULL, the function returns NULL.*/

char *repeat(char *s, int x, char sep) {
    if(s) {
        int stringLength = 0;
        int index = 0;
        int numOfSep = x - 1;
        char *ptr1 = s;
        
        while(*ptr1 != '\0') {
            stringLength++;
            ptr1++;
        }
        
        char *resultString = malloc(stringLength * x + numOfSep + 1);
        
        if(resultString) {
            char *ptr2 = resultString;
            
            for(index = 0; index < x; ++index) {
                char *ptr1 = s;
                
                while(*ptr1) {
                    *ptr2 = *ptr1;
                    ptr1++;
                    ptr2++;
                }
                
                if(numOfSep > 0) {
                    *ptr2 = sep;
                    ptr2++;
                    numOfSep--;
                }
            }
            
            *ptr2 = '\0';
        }
        
        return resultString;
    } else {
        return NULL;
    }
}
