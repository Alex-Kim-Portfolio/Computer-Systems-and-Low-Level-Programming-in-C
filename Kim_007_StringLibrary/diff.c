//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Returns the number of positions in which s1 and s2 differ (number of changes needed to transform s1 into s2, where a change could be a character substitution, insertion, or deletion).*/

int diff(char *s1, char *s2) {
    int diffInStringLength = 0;
    int numDifferingChars = 0;
    int totalNumPos = 0;
    
    char *ptr1 = s1;
    int stringLength1 = 0;
    char *ptr2 = s2;
    int stringLength2 = 0;
    
    //Get length of first string s1
    while(*ptr1 != '\0') {
        stringLength1++;
        ptr1++;
    }
    //Get length of second string s2
    while(*ptr2 != '\0') {
        stringLength2++;
        ptr2++;
    }
    
    if(stringLength1 <= stringLength2) {
        diffInStringLength = stringLength2 - stringLength1;
        
        //Loop through the shorter string
        for(int i = 0; i < stringLength1; ++i) {
            if(s1[i] != s2[i]) {
                numDifferingChars++;
            }
        }
    } else {
        diffInStringLength = stringLength1 - stringLength2;
        
        //Loop through the shorter string
        for(int i = 0; i < stringLength2; ++i) {
            if(s2[i] != s1[i]) {
                numDifferingChars++;
            }
        }
    }
    
    totalNumPos = numDifferingChars + diffInStringLength;
    
    return totalNumPos;
}
