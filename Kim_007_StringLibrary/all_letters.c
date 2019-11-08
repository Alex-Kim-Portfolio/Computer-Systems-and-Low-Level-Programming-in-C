//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Returns 1 if all of the characters in the string are either upper- or lower-case letters of the alphabet. Returns 0 otherwise.*/

int all_letters(char *s) {

    int stringLength = 0;
    char *ptr = s;
    int result = 0;

    //Find the length of the string
    while(*ptr != '\0') {
        stringLength++;
        ptr++;
    }
    
    char stringCopy[stringLength];
    
    for(int i = 0; i < stringLength; ++i) {
        stringCopy[i] = s[i];
    }

    for(int i = 0; i < stringLength; ++i) {
        char lowerCaseChar = tolower(stringCopy[i]);
        
        if(((lowerCaseChar >= 'a') && (lowerCaseChar <= 'z')) || (tolower(stringCopy[i]) == ' ')) {
            result = 1;
        } else {
            result = 0;
            break;
        }
    }

    return result;
}
