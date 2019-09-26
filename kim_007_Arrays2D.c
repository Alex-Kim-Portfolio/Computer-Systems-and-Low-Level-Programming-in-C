//Alexander Kim
//9.24.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab05 2DArrays & Arrays of Pointers to Functions (Part 1)
//No issues/problems, the program compiles and runs.

//Tell the preprocessor to go and include source code from these files to use in this program
#include <stdio.h>
#include <stdbool.h>


//Declaring static variables to use across the entire file. Saved separately in memory
static int rows;
static int columns;

//Function prototypes
int max(int array[][columns]);
int rowSum(int numberRow, int array[][columns]);
int columnSum(int numberColumn, int array[][columns]);
bool isSquare(int array[][columns]);
void displayOutputs(int array[][columns]);


//Main function
int main() {
    
    //Initialize variables
    int entry = 0;
    int numberRow = 0;
    int numberColumn = 0;
    bool validInput = false;
    
    //Ask the user to specify the number of rows and columns in the 2D array
    printf("\nLet's create a 2Dim array!\n\n");
    printf("\tHow many rows? ");
    scanf("%d", &rows);
    
    printf("\tHow many columns? ");
    scanf("%d", &columns);
    printf("\n");
    
    //Create the 2D array by asking the user for the value at each position in the 2D array
    int multiDimArray[rows][columns];

    for(size_t i = 0; i < rows; ++i) {
        for(size_t j = 0; j < columns; ++j) {
            printf("\tenter [%zu][%zu]: ", i, j);
            scanf("%d", &entry);
            multiDimArray[i][j] = entry;
        }
    }
    
    //Call the max function and print the result
    printf("\n\nMaximum value in the array = %d", max(multiDimArray));
    
    //Ask the user for the row and column to sum up and call and display results from rowSum and columnSum functions
    do {
        printf("\n\nPlease enter the row number that you would like to sum up: ");
        scanf("%d", &numberRow);
        if(numberRow <= 0 || numberRow > rows) {
            printf("\nThat row does not exist.");
            validInput = false;
        } else {
            validInput = true;
        }
    } while(validInput == false);
    
    printf("\n\nThe sum of row %d = %d", numberRow, rowSum((numberRow-1), multiDimArray));
    
    
    do {
        printf("\n\nPlease enter the column number that you would like to sum up: ");
        scanf("%d", &numberColumn);
        if(numberColumn <= 0 || numberColumn > columns) {
            printf("\nThat column does not exist.");
            validInput = false;
        } else {
            validInput = true;
        }
    } while(validInput == false);
    
    printf("\n\nThe sum of column %d = %d", numberColumn, columnSum((numberColumn-1), multiDimArray));
    
    //Call the isSquare function and return result
    if(isSquare(multiDimArray) == true) {
        printf("\n\nThis is a square array.");
    } else {
        printf("\n\nThis is not a square array.");
    }
    
    //Call the displayOutputs function
    printf("\n\nHere is your 2Dim array:\n");
    displayOutputs(multiDimArray);
    
    return 0;
} //End of main



//This function returns the maximum value in the 2D array
int max(int array[][columns]) {
    int max = 0;
    int currentElement = 0;
    
    for (size_t i = 0; i < rows; ++i){
        for(size_t j = 0; j < columns; ++j) {
            if (array[i][j] > max){
                max = array[i][j];
            }
        }
    }
    
    return max;
} //End of max


//This function returns the sum of a specified row in the 2D array
int rowSum(int numberRow, int array[][columns]) {
    int sum = 0;
    
    for(size_t i = 0; i < columns; ++i) {
        sum += array[numberRow][i];
    }
    
    return sum;
} //End of rowSum



//This function returns the sum of a specified column in the 2D array
int columnSum(int numberColumn, int array[][columns]) {
    int sum = 0;
    
    for(size_t i = 0; i < rows; ++i) {
        sum += array[i][numberColumn];
    }
    
    return sum;
} //End of columnSum



//This function indicates whether or not the 2D array is a square
bool isSquare(int array[][columns]) {
    if(rows/columns == 1) {
        return true;
    } else {
        return false;
    }
} //End of isSquare



//This function formats and prints the 2D array to the console
void displayOutputs(int array[][columns]) {
    for(size_t i = 0; i < rows; ++i) {
        printf("[");
        for(size_t j = 0; j < columns; ++j) {
            if(j+1 == columns) {
                printf("%d", array[i][j]);
            } else {
                printf("%d, ", array[i][j]);
            }
        }
        printf("]\n");
    }
} //End of displayOutputs
