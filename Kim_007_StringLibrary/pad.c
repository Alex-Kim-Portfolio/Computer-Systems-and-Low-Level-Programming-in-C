//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

/* Returns a new string consisting of all of the letters of s, but padded with spaces at the end so that the total length of the returned string is an even multiple of d. If the length of s is already an even multiple of d, the function returns a copy of s.*/

char *pad(char *s, int d) {
    int stringLength = 0;
    char *ptr = s;
    char *result = s;
    
    //See if s is NULL, then return NULL. If not, then proceed.
    if(*ptr == NULL) {
        
        result = NULL;
        
    } else {
        
        //Find length of string
        while(*ptr != '\0') {
            stringLength++;
            ptr++;
        }
        
        //Find if string length is multiple of d (stringlength % d == 0)
        if((stringLength % d) == 0) {
            
            result = s;
            
        } else {
            int nextMultiple = stringLength;
            int numOfWhiteSpacesNeeded = 0;
            
            //Find the next int value after string length int that is a multiple of d
            while((nextMultiple % d) != 0) {
                nextMultiple++;
            }
            
            //Take that string length and subtract it from the next int value that's a multiple of d. This is the number of whitespace that needs to be added to the end of the string.
            numOfWhiteSpacesNeeded = nextMultiple - stringLength;
            
            //Copy the string into a new array that is the size of stringlength + number of whitespaces needed
            char resultString[stringLength + numOfWhiteSpacesNeeded];
            
            for(int i = 0; i < (stringLength + numOfWhiteSpacesNeeded); ++i) {
                if(i >= stringLength) {
                    resultString[i] = ' ';
                } else {
                    resultString[i] = s[i];
                }
            }
            
            //Create a pointer to the new array and return the pointer
            result = resultString;
        }
    }
    
    return result;
}
