//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Removes whitespace characters from the beginning of s.*/

void rm_left_space(char *s) {
    char *ptr = s;

    while(*ptr == ' ') {
        ptr++;
    }

    s = ptr;

    printf("\"%s\"\n", s);
}
