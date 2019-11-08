//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Changes s so that the first letter of every word is in upper case and each additional letter is in lower case. */

void capitalize(char *s) {
    int stringLength = 0;
    char *ptr = s;

    while(*ptr != '\0') {
        stringLength++;
        ptr++;
    }

    char stringCopy[stringLength + 1];
    stringCopy[stringLength] = '\0';

    for(int i = 0; i < stringLength; ++i) {
        stringCopy[i] = s[i];
    }

    stringCopy[0] = toupper(stringCopy[0]);

    char *firstIndex = &stringCopy[1];
    char *secondIndex = &stringCopy[2];

    for(int i = 2; i < stringLength; ++i) {
        
        if((*firstIndex == ' ') && (*secondIndex != ' ')) {
            stringCopy[i] = toupper(stringCopy[i]);
        }
        
        firstIndex++;
        secondIndex++;
    }

    printf("%s\n", stringCopy);
}
