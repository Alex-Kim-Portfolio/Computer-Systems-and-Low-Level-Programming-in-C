//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Removes any empty strings */

void rm_empties(char **words) {
    int index = 0;
    int arrayLength = 0;
    int stringLength = 0;
    
    while(words[index] != NULL) {
        arrayLength++;
        index++;
    }

    for(int i = 0; i < arrayLength; ++i) {
        if(is_empty(words[i]) == 1) {
            for(int j = i; j < arrayLength; ++j) {
                words[j] = words[j+1];
            }
            arrayLength--;
            i--;
        }
    }
    
    for(int i = 0; i < arrayLength; ++i) {
        if(i == arrayLength - 1) {
            printf("%s\n", words[i]);
        } else {
            printf("%s ", words[i]);
        }
    }
    
    printf("\n");
}
