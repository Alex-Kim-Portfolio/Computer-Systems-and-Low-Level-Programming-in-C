//Alexander Kim
//9.20.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab04 Processing 1D Arrays
//No issues/problems, the program compiles and runs.


//Tell the preprocessor to go and include source code from these files to use in this program.
//Define minimum and maximum range of values for the random number generator function

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define RAND_MIN 0
#define RAND_MAX 100
#define SIZE 40

//Function prototypes

void fillArray(int array[], int size);
int findWithRange(int array[]);
void reverseArray(int array[]);
void reverseArrayBetweenTwoIndices(int array[]);
int findSequence(int array[]);


//Main Function

int main(int argc, const char * argv[]) {
    
    //Delcare an array of size 40 (constant defined)
    int array[SIZE];
    
    //Call the fillArray method to fill the array with 40 numbers randomly selected within a range of 0 to 100
    fillArray(array, SIZE);
    
    //Print out the newly filled array
    printf("\n\n================================Array================================\n");
    
    for(int i = 0; i < SIZE; ++i) {
        printf("%d ", array[i]);
    }
    
    //Call the findWithRange method and print out the max value between the selected indices
    printf("\n\nMax element in array between specified indices: %d\n", findWithRange(array));
    
    //Call the reverseArray function
    reverseArray(array);
    
    //Call the reverseArrayBetweenTwoIndices function
    reverseArrayBetweenTwoIndices(array);
    
    //Call the findSequence function and assign its return value to the variable findSequenceResult. Print out the appropriate message based on if the sequence was found or not.
    int findSequenceResult = findSequence(array);
    
    if (findSequenceResult == -1) {
        printf("Sequence not found\n\n");
    } else {
        printf("Sequence found at index %d\n\n", findSequenceResult);
    }
    
} //End of main function



//fillArray function

void fillArray(int array[], int size) {
    
    //Pass the srand function a seed (by setting the computer's internal clock as the seed) to generate purely random numbers when rand() is called
    srand((unsigned)time(NULL));
    
    //Loop through the array in input the random number at each index
    for (size_t i = 0; i < SIZE; ++i) {
        //Modulus gives a random result between RAND_MAX and RAND_MIN (inclusive)
        array[i] = rand() % (RAND_MAX + 1) + RAND_MIN;
    }
    
} //End of fillArray function



//findWithRange function

int findWithRange(int array[]) {
    
    //Declare and initialize variables
    int max = 0;
    int lowIndex = 0;
    int highIndex = 0;
    bool inputValid = false;
    
    printf("\n\n\n================================findWithRange================================\n");
    
    //Prompt the user for input as long as the input is invalid
    do {
        printf("Please enter low index: ");
        scanf("%d", &lowIndex);
        
        if(lowIndex < 0 || lowIndex >= SIZE - 1) {
            printf("\nLow index must be greater than or equal to 0 and less than the maximum index of the array (39).\n\n");
        } else {
            printf("\n\nPlease enter high index: ");
            scanf("%d", &highIndex);

            if(highIndex < lowIndex || highIndex > SIZE - 1) {
                printf("\n\nHigh index must be greater than low index and less than or equal to the maximum index of the array (39).\n\n");
            } else {
                inputValid = true;
            }
        }
    } while (inputValid == false);
    
    //If input is valid, loop through the low index to the high index specified by the user and find the maximum value
    for(int i = lowIndex; i <= highIndex; ++i) {
        if(array[i] > max) {
            max = array[i];
        } else {
            continue;
        }
    }
    
    //Return the maximum value between those two indices
    return max;

}



//reverseArray function

void reverseArray(int array[]) {
    
    //Declare and intialize variables
    int temp = 0;
    int minIndex = 0;
    int maxIndex = SIZE - 1;
    
    //Reverse the array by moving pointer variables from both ends of the array to eventually meet in the middle while swapping the values at each pointer variable before incrementing and decrementing
    while(minIndex <= maxIndex) {
        temp = array[minIndex];
        array[minIndex] = array[maxIndex];
        array[maxIndex] = temp;
        minIndex++;
        maxIndex--;
    }
    
    printf("\n\n\n\n================================Reverse Array================================\n");
    
    //Print the reversed array
    for(int i = 0; i < SIZE; ++i) {
        printf("%d ", array[i]);
    }
    
    printf("\n\n");
    
} //End of reverseArray



//reverseArrayBetweenTwoIndices function

void reverseArrayBetweenTwoIndices(int array[]) {
    
    //Declare and intialize variables
    int low = 0;
    int high = 0;
    int temp = 0;
    bool inputValid = false;
    
    printf("\n\n\n================================reverseArrayBetweenTwoIndices================================\n");
    
    //Prompt the user for input as long as the input is invalid
    do {
        printf("Please enter low index: ");
        scanf("%d", &low);
        
        if(low < 0 || low >= SIZE - 1) {
            printf("\nLow index must be greater than or equal to 1 and less than the maximum index of the array (39).\n\n");
        } else {
            printf("\n\nPlease enter high index: ");
            scanf("%d", &high);
            
            if(high < low || high > SIZE - 1) {
                printf("\n\nHigh index must be greater than low index and less than or equal to the maximum index of the array (39).\n\n");
            } else {
                inputValid = true;
            }
        }
    } while (inputValid == false);
    
    //If the input is valid, reverse the array by moving pointer variables from both low and high to eventually meet in the middle while swapping the values at low and high before incrementing and decrementing
    while(low < high) {
        temp = array[low];
        array[low] = array[high];
        array[high] = temp;
        low++;
        high--;
    }
    
    printf("\n\n\n===========================Reversed Array Between Indices===========================\n");
    
    //Print out the newly modified array
    for(int i = 0; i < SIZE; ++i) {
        printf("%d ", array[i]);
    }
    
    printf("\n\n");
    
} //End of reverseArrayBetweenTwoIndices



//findSequence function

int findSequence(int array[]) {
    
    //Declare and initialize variables
    int seqNum1 = 0;
    int seqNum2 = 0;
    bool seqFound = false;
    
    printf("\n\n\n================================findSequence================================\n");

    //Prompt the user for two numbers (a sequence) to be searched for in the array
    printf("Please enter two numbers (a sequence) to find in the array: ");
    scanf("%d %d", &seqNum1, &seqNum2);
    
    //Loop through the array and try to locate the sequence. If found return the index where the first element in the sequence was found
    for(int i = 0; i < SIZE; ++i) {
        if (array[i] == seqNum1 && array[i+1] == seqNum2) {
            return i;
            seqFound = true;
            break;
        } else {
            continue;
        }
    }
    
    //If the sequence is not found return -1
    if(seqFound == false) {
        return -1;
    }
    
} //End of findSequence
