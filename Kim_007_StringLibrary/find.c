//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Returns the index of the first occurrence of n in the string h or -1 if it isn't found.*/

int find(char *h, char *n) {
    int index = 0;
    int wordFound = 0;
    int stringLength = 0;
    char *ptr = h;

    while(*ptr != '\0') {
        stringLength++;
        ptr++;
    }

    char stringCopy[stringLength + 1];

    for(int i = 0; i < stringLength; ++i) {
        stringCopy[i] = h[i];
    }

    stringCopy[stringLength + 1] = '\0';

    while(stringCopy[index] != '\0') {
        if(stringCopy[index] == n[0]) {
            int j = 0;
            wordFound = 1;

            while(n[j] != '\0') {
                if(stringCopy[index + j] != n[j]) {
                    wordFound = 0;
                    break;
                }

                j++;
            }

        }

        if(wordFound == 1) {
            break;
        }

        index++;
    }

    if (wordFound == 1) {
        return index;
    } else {
        return -1;
    }
}
