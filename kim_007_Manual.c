/*
 * Name:	Alexander Kim
 * Section:	CIS 2107-007
 * Date:	10/22/2019
 * Lab:  	CIS2107_Lab07_Manual 
 * Goal: 	To design and implement functions to process characters and strings. No issues. The program compiles and runs.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define RAND_MIN 0
#define RAND_MAX 100

//functions
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[], int size);
void endsWithed(char *string[], int size);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f\n", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    int size = sizeof(series) / sizeof(series[0]);
    startsWithB(series, size);

    //test for endsWithed
    endsWithed(series, size);

}




// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char * s) {
    //Create a character array and copy the string from s into array (so it can be modified)
    char array[100];
    strcpy(array, s);

    //Change the contents of the array to uppercase
    for(int i = 0; i < strlen(array); ++i) {
        array[i] = toupper(array[i]);
    }
    
    //Print the string in uppercase
    printf("%s\n", array);
    
    //Change the contents of the array to lowercase
    for(int i = 0; i < strlen(array); ++i) {
        array[i] = tolower(array[i]);
    }
    
    //Print the string in lowercase
    printf("%s\n", array);
}




// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    //Declare 4 ints to hold the strings
    int num1, num2, num3, num4;
    
    //Use sscanf() to read in strings s1, s2, s3, s4 as int format, and store them in num1, num2, num3, and num4
    sscanf(s1, "%d", &num1);
    sscanf(s2, "%d", &num2);
    sscanf(s3, "%d", &num3);
    sscanf(s4, "%d", &num4);
    
    //Add up the integers
    int sum = num1 + num2 + num3 + num4;
    
    //Return the sum of integers
    return sum;
}




//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    //Declare 4 doubles to hold the strings
    double num1, num2, num3, num4;
    
    //Use sscanf() to read in strings s1, s2, s3, s4 as double format, and store them in num1, num2, num3, and num4
    sscanf(s1, "%lf", &num1);
    sscanf(s2, "%lf", &num2);
    sscanf(s3, "%lf", &num3);
    sscanf(s4, "%lf", &num4);
    
    //Add up the doubles
    double sum = num1 + num2 + num3 + num4;
    
    //Returns the sum of doubles
    return sum;
}




//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
    //Declare and initialize result variable
    int result = 0;
    
    //Use strcmp to compare s1 and s2 and store the integer result in the result variable
    result = strcmp(s1, s2);
    
    //Display the appropriate message depending on the value stored in result
    if(result < 0) {
        printf("\n\n%s < %s\n", s1, s2);
    } else if (result > 0) {
        printf("\n\n%s > %s\n", s1, s2);
    } else if (result == 0) {
        printf("\n\n%s = %s\n", s1, s2);
    }
}




//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
    //Declare and initialize result variable
    int result = 0;
    
    //Use strncmp to compare the first n chars of s1 and s2 and store the integer result in the result variable
    result = strncmp(s1, s2, n);
    
    //Display the appropriate message depending on the value stored in result
    if(result < 0) {
        printf("\nComparison of first %d chars: %s < %s\n", n, s1, s2);
    } else if (result > 0) {
        printf("\nComparison of first %d chars: %s > %s\n", n, s1, s2);
    } else if (result == 0) {
        printf("\nComparison of first %d chars: %s = %s\n", n, s1, s2);
    }
}




//6.(Random Sentences) 
void randomize(void) {
    //Create four arrays of pointers and initialize each array
    char *articles[] = {"the", "a", "one", "some", "any"};
    char *noun[] = {"boy", "girl", "dog", "town", "car"};
    char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[] = {"to", "from", "over", "under", "on"};
    
    //Create a result char array and allocate space
    char result[100];
    
    //Passing srand a seed to create truly random number
    srand((unsigned)time(NULL));
    
    //Generate a random number, and use that number to grab a random word from the appropriate array and add it to the result array. Add spaces in between each word.
    strcat(result, articles[(rand() % (RAND_MAX+ 1) + RAND_MIN) % 5]);
    //Capitalize first letter in the sentence.
    result[0] = toupper(result[0]);
    strcat(result, " ");
    
    strcat(result, noun[(rand() % (RAND_MAX+ 1) + RAND_MIN) % 5]);
    strcat(result, " ");
    
    strcat(result, verb[(rand() % (RAND_MAX+ 1) + RAND_MIN) % 5]);
    strcat(result, " ");
    
    strcat(result, preposition[(rand() % (RAND_MAX+ 1) + RAND_MIN) % 5]);
    strcat(result, " ");
    
    strcat(result, articles[(rand() % (RAND_MAX+ 1) + RAND_MIN) % 5]);
    strcat(result, " ");
    
    strcat(result, noun[(rand() % (RAND_MAX+ 1) + RAND_MIN) % 5]);
    //Add a period to the end of the sentence.
    strcat(result, ".\n");
    
    //Print the final sentence stored in result
    printf("\n\n%s", result);
}




//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
    //Create a char array to hold the area code which is tokenized
    char areaCode[50];
    //Create a char array to hold the seven digit phone number which is tokenized
    char phoneNum[50];
    
    //Get the area code
    char *tokenPtr = strtok(num, "()");
    strcpy(areaCode, tokenPtr);
    
    //Get the next three digits in the number
    tokenPtr = strtok(NULL, "-");
    strcpy(phoneNum, tokenPtr);
    
    //Get the last four digits in the number and concatenate it with the previous three numbers
    tokenPtr = strtok(NULL, "");
    strcat(phoneNum, tokenPtr);
    
    printf("\n\n");
    
    //Print the tokens
    printf("%s%s", areaCode, phoneNum);
    
    printf("\n\n");
}




//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    //Begin tokenizing the sentence called text, with the whitespace separator as the signal to tokenize
    char *tokenPtr = strtok(text, " ");
    //Create an array of pointers
    char *array[50];
    //Initialize counter variables
    int numOfTokens = 0;
    int j = 0;
    int i = 0;
    
    //Continue to tokenize the sentence until tokenPtr becomes NULL
    while(tokenPtr != NULL) {
        //Takes the token memory location and inserts it into the jth index
        array[j] = tokenPtr;
        //Goes and gets the next token
        tokenPtr = strtok(NULL, " ");
        //Increase the number of tokens by 1
        numOfTokens++;
        //Increase the index counter variable
        j++;
    }
    
    //Since j is outside of the range of tokens by one after the for loop, we bring it back by 1, and so j points to the last index in the array
    j = j - 1;
    
    //Reverse the array (AKA reverse the array that holds token memory addresses)
    while(i < j) {
        char *temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
    
    //Print out the newly reversed array of tokens
    for(int k = 0; k < numOfTokens; ++k) {
        printf("%s ", array[k]);
    }
    
    printf("\n");
}




//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
    int numOfOccur = 0;
    
    //Check to see if the strstr function returns a pointer or null pointer. If it returns a pointer, move the pointer for the string/line to the position of the pointer the strstr function returns.
    while((line = strstr(line, sub)) != NULL) {
        //Increment the count for the number of occurrences of the substring.
        numOfOccur++;
        //Move the pointer to one after the position that strstr returns.
        line++;
    }
  
    return numOfOccur;
}




//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
    int numOfOccur = 0;
    
    //Check to see if the strchr function returns a pointer or null pointer. If it returns a pointer, move the pointer for the string/line to the position of the pointer the strchr function returns.
    while((line = strchr(line, c)) != NULL) {
        //Increment the count for the number of occurrences of the character.
        numOfOccur++;
        //Move the pointer to one after the position that strchr returns.
        line++;
    }
    
    return numOfOccur;
}





//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
    //Declare a char array called stringCopy and allocate memory
    char stringCopy[100];
    //Intiate another array called letterCount, which will hold the count of a specific letter found in the stringCopy
    int letterCount[26] = {0};
    
    //Copy the contents of the string literal string into the character array stringCopy
    strcpy(stringCopy, string);
    
    //For each letter/character in stringCopy...
    for(int i = 0; i < strlen(stringCopy); ++i) {
        //Check to see if it's one of the 26 letters in the alphabet...
        for(int j = 0; j < 26; ++j) {
            //If it is, then increment the appropriate index in the letterCount array and break out of the loop to move to the next character in stringCopy.
            if(tolower(stringCopy[i]) == ('a' + j)) {
                letterCount[j]++;
                break;
            }
        }
    }
    
    printf("\n\n");
    
    //Print out the results and the number of each letter found in the string
    for(int k = 0; k < 26; ++k) {
        printf("%c,%c | %d\n", toupper('a' + k), 'a' + k, letterCount[k]);
    }
}




//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
    //Declare and initialize a variable to hold the number of words
    int wordCount = 0;
    //Declare a char array phrase with size 100
    char phrase[100];
    
    //Copy the contents of the string literal into the char array
    strcpy(phrase, string);
    
    //Begin to tokenize the string
    char *tokenPtr = strtok(phrase, " ");
    
    //While the tokenPtr has not reached null, increment the word count for each word found or move on if the tokenPtr reaches a null terminator
    if (tokenPtr != NULL) {
        wordCount++;
        while(tokenPtr != NULL) {
            tokenPtr = strtok(NULL, " ");
            if(tokenPtr != NULL) {
                wordCount++;
            } else {
                break;
            }
        }
    }
   
    //Return the number of words (tokens) in the string
    return wordCount;
}




//13.(Strings Starting with "b") 
void startsWithB(char *string[], int size) {
    //Create a string literal (pointer to char) tempHolder to temporarily hold another string literal
    char *tempHolder;
    
    printf("\n\n");
    
    //Iterate through each string literal in array of string literals (pointers to char)
    for(int i = 0; i < size; ++i) {
        //Store the current index's string literal in tempHolder
        tempHolder = string[i];
        //If the first character of that string starts with b, print the string literal at that index
        if(tolower(tempHolder[0]) == 'b') {
            printf("%s ", string[i]);
        }
    }
    
    printf("\n");
}




//14.(Strings Ending with "ed") 
void endsWithed(char *string[], int size) {
    //Create a string literal (pointer to char) tempHolder to temporarily hold another string literal
    char *tempHolder;
    
    printf("\n");
    
    //Iterate through each string literal in array of string literals (pointers to char)
    for(int i = 0; i < size; ++i) {
        //Store the current index's string literal in tempHolder
        tempHolder = string[i];
        //Initialize last index and second to last index int values
        int lastIndex = strlen(tempHolder) - 1;
        int secondToLastIndex = strlen(tempHolder) - 2;
        //If the string at this index ends with "ed", print the string literal
        if((tempHolder[secondToLastIndex] == 'e') && (tempHolder[lastIndex] == 'd')) {
            printf("%s ", string[i]);
        }
    }
    
    printf("\n\n");
}
