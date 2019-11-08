//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Returns a new string based on s, but without any duplicate characters.*/

char *dedup(char *s) {
    int stringLength = 0;
    int index = 0;
    char *ptr1 = s;
    
    while(*ptr1 != '\0') {
        stringLength++;
        ptr1++;
    }
    
    char stringCopy[stringLength];
    stringCopy[stringLength] = '\0';
    
    for(int i = 0; i < stringLength; ++i) {
        stringCopy[i] = s[i];
    }
    
    for(int i = 0; i < stringLength; ++i) {
        for(int j = i + 1; stringCopy[j] != '\0'; ++j) {
            if(stringCopy[i] == stringCopy[j]) {
                for(int k = j; stringCopy[k] != '\0'; ++k) {
                    stringCopy[k] = stringCopy[k + 1];
                }
            }
        }
    }
    
    char *result = stringCopy;
    
    return result;
}
