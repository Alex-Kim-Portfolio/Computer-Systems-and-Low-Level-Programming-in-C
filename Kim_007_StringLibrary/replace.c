//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Returns a copy of the string s, but with each instance of pat replaced with rep..*/

char *replace(char *s, char *pat, char *rep) {
    int stringLength = 0;
    int patLength = 0;
    int repLength = 0;
    int numOfPat = 0;
    char *ptr = s;
    char *newString = NULL;

    while(*ptr != '\0') {
        stringLength++;
        ptr++;
    }

    ptr = pat;

    while(*ptr != '\0') {
        patLength++;
        ptr++;
    }

    ptr = rep;

    while(*ptr != '\0') {
        repLength++;
        ptr++;
    }

    ptr = s;

    //Find number of times pat occurs in the string
    while(*ptr != '\0') {
        if(ptr_to(ptr, pat) == ptr) {
            numOfPat++;
            ptr += patLength - 1;
        }

        ptr++;
    }

    if(repLength > patLength) {
        newString = malloc(stringLength + (numOfPat * (repLength - patLength)) + 1);
        char *ptr1 = s;
        char *ptr2 = newString;

        while(*ptr1 != '\0') {
            if(ptr_to(ptr1, pat) == ptr1) {
                for(int i = 0; i < repLength; ++i) {
                    *ptr2 = rep[i];
                    ptr2++;
                }
                ptr1 += patLength;
            } else {
                *ptr2 = *ptr1;
                ptr1++;
                ptr2++;
            }
        }

        *ptr2 = '\0';
    } else if (repLength < patLength) {
        newString = malloc(stringLength + (numOfPat * (repLength - patLength)) + 1);
        char *ptr1 = s;
        char *ptr2 = newString;

        while(*ptr1 != '\0') {
            if(ptr_to(ptr1, pat) == ptr1) {
                for(int i = 0; i < repLength; ++i) {
                    *ptr2 = rep[i];
                    ptr2++;
                }
                ptr1 += patLength;
            } else {
                *ptr2 = *ptr1;
                ptr1++;
                ptr2++;
            }
        }

        *ptr2 = '\0';
    } else {
        newString = malloc(stringLength + (numOfPat * (repLength - patLength)) + 1);
        char *ptr1 = s;
        char *ptr2 = newString;

        while(*ptr1 != '\0') {
            if(ptr_to(ptr1, pat) == ptr1) {
                for(int i = 0; i < repLength; ++i) {
                    *ptr2 = rep[i];
                    ptr2++;
                }
                ptr1 += patLength;
            } else {
                *ptr2 = *ptr1;
                ptr1++;
                ptr2++;
            }
        }

        *ptr2 = '\0';
    }

    return newString;
}
