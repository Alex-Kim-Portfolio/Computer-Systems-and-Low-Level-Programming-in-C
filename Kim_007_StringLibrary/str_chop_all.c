//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Returns an array of strings consisting of the characters in s split into tokens based on the delimiter c, followed by a NULL pointer.*/

char **str_chop_all(char *s, char c){
    int index = 0;
    int numOfTokens = 0;
    int beginningOfString = 0;
    int tokenLength = 0;
    char *ptr = s;
    
    while(*ptr != '\0') {
        if(*ptr == c) {
        numOfTokens++;
        }
        ++ptr;
    }

    char **result = malloc(sizeof(char *) * (numOfTokens + 2));
    ptr = s;
    int i = 0;

    while(*ptr != '\0') {
        if(*ptr == c) {
            result[index] = malloc((tokenLength + 1) * sizeof(char));
            
            int j = 0;
            for(j = 0; j < tokenLength; j++) {
                result[index][j] = (s + beginningOfString)[j];
            }
            
            result[index][i] = '\0';
            index++;
            tokenLength = 0;
            beginningOfString = i + 1;
        } else {
            tokenLength++;
        }
        ptr++;
        i++;
    }

    if(beginningOfString != i) {
        result[index] = malloc((tokenLength + 1) * sizeof(char));
        
        int j = 0;
        for(j = 0; j < tokenLength; j++) {
            result[index][j] = (s + beginningOfString)[j];
        }
        
        result[index][i] = '\0';
        index++;
    }
    
    result[index] = NULL;

    return result;
}
