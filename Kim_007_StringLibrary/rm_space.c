//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Removes whitespace characters from the beginning and the ending s.*/

void rm_space(char *s) {
    int stringLength = 0;
    char *ptr = s;

    while(*ptr != '\0') {
        stringLength++;
        ptr++;
    }

    ptr--;

    while(*ptr == ' ') {
        stringLength--;
        ptr--;
    }

    char *ptr2 = s;

    while(*ptr2 == ' ') {
        stringLength--;
        ptr2++;
    }

    char stringCopy[stringLength];

    for(int i = 0; i < stringLength; i++) {
        stringCopy[i] = *(ptr2 + i);
    }

    printf("\"%s\"", stringCopy);
}
