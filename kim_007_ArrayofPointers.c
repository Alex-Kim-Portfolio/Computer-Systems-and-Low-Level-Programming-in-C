//Alexander Kim
//9.25.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab05 2DArrays & Arrays of Pointers to Functions (Part 2)
//No issues/problems, the program compiles and runs.


//Tell the preprocessor to go and include source code from these files to use in this program
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//Create static variables to be used throughout the file. Variables are stored separately in memory.
static int students = 0;
static int exams = 0;


//Function prototypes
void printArray(const int grades[][exams], size_t pupils, size_t tests);
void minimum(const int grades[][exams], size_t pupils, size_t tests);
void maximum(const int grades[][exams], size_t pupils, size_t tests);
void average(const int grades[][exams], size_t pupils, size_t tests);


//Main function
int main(void) {
    
    //Initialize variables
    int entry = 0;
    int userChoice = 0;
    bool validInput = false;
    bool keepGoing = true;
    
    //Ask the user for the number of students while the input is not valid
    do {
        printf("\n\nPlease enter the number of students: ");
        scanf("%d", &students);
        
        if(students <= 0) {
            printf("\nYou cannot have 0 or negative students.");
            validInput = false;
        } else {
            validInput = true;
        }
    } while(validInput == false);
    
    //Ask the user for the number of exams while the input is not valid
    do {
        printf("\nPlease enter the number of exams: ");
        scanf("%d", &exams);
        
        if(students <= 0) {
            printf("\nYou cannot have 0 or negative exams.");
            validInput = false;
        } else {
            validInput = true;
        }
    } while(validInput == false);

    printf("\n\n");
    
    //Create a 2D array to hold the data
    int studentGrades[students][exams];
    
    //Ask the user for each student's grade on each exam, and fill the array in with the data
    for(size_t i = 0; i < students; ++i) {
        for(size_t j = 0; j < exams; ++j) {
            printf("\tEnter student %lu exam %lu grade: ", (i+1), (j+1));
            scanf("%d", &entry);
            studentGrades[i][j] = entry;
        }
    }
    
    //Create an array of pointers that point to each function (specified in function prototype)
    void (*processGrades[4])(const int grades[][exams], size_t pupils, size_t tests) = {printArray, minimum, maximum, average};
    
    //Continue to display the menu and ask the user for a menu choice as long as the user does not press 4
    do {
        printf("\n\n\nEnter a choice:\n\t0 Print the array of grades\n\t1 Find the minimum grade\n\t2 Find the maximum grade\n\t3 Print the average on all tests for each student\n\t4 End Program\n\n");
        printf("Enter your number choice: ");
        scanf("%d", &userChoice);
        
        //Depending on user choice, invoke the appropriate function in the array of pointers *processGrades, while passing in the appropriate arguments to that function. If the selection is 4, terminate the program.
        if(userChoice == 0) {
            (*processGrades[0])(studentGrades, students, exams);
            keepGoing = true;
        } else if(userChoice == 1) {
            (*processGrades[1])(studentGrades, students, exams);
            keepGoing = true;
        } else if(userChoice == 2) {
            (*processGrades[2])(studentGrades, students, exams);
            keepGoing = true;
        } else if(userChoice == 3) {
            (*processGrades[3])(studentGrades, students, exams);
            keepGoing = true;
        } else if(userChoice == 4) {
            printf("\nThank you. Goodbye!\n\n");
            exit(0);
        } else {
            printf("\nThat is not a valid choice. Please try again.");
            keepGoing = true;
        }
    } while(keepGoing == true);
    
} //End of main


//This function prints the array of each student's exam grades
void printArray(const int grades[][exams], size_t pupils, size_t tests) {
    
    printf("\n\nThe array is:\n");
    
    //Display each student's exam grades
    for(size_t i = 0; i < pupils; ++i) {
        
        printf("\nStudent %zu's grades: ", i);
        
        for(size_t j = 0; j < tests; ++j) {
            printf("%d, ", grades[i][j]);
        }
        printf("\n");
        
    }
    
} //End of printArray


//This function prints the minimum exam grade out of the entire array
void minimum(const int grades[][exams], size_t pupils, size_t tests) {
    
    //Set the lowGrade to the highest possible value
    int lowGrade = 100;
    
    //Loop through the array, and if a value is less than the current minimum, replace the minimum with that value
    for(size_t i = 0; i < pupils; ++i) {
        for(size_t j = 0; j < tests; ++j) {
            if(grades[i][j] < lowGrade) {
                lowGrade = grades[i][j];
            }
        }
    }
    
    //Print the minimum value
    printf("\nLowest grade: %d", lowGrade);
    
} //End of minimum


//This function prints the maximum exam grade out of the entire array
void maximum(const int grades[][exams], size_t pupils, size_t tests) {
    
    //Set the highGrade to the lowest possible value
    int highGrade = 0;
    
    //Loop through the array, and if a value is greater than the current maximum, replace the maximum with that value
    for(size_t i = 0; i < pupils; ++i) {
        for(size_t j = 0; j < tests; ++j) {
            if(grades[i][j] > highGrade) {
                highGrade = grades[i][j];
            }
        }
    }
    
    //Print the maximum value
    printf("\nHighest grade: %d", highGrade);
    
} //End of maximum


//This function prints the exam average of each student
void average(const int grades[][exams], size_t pupils, size_t tests) {
    
    //Initialize the average variable
    double average = 0.0;
    
    printf("\n");
    
    //Loop through each student's exam totals and calculate the average for each student and display it
    for(size_t i = 0; i < pupils; ++i) {
        //Reset the total sum of exam grades to 0 for each student
        int total = 0;
        
        //Sum up the exam grades for the student
        for(size_t j = 0; j < tests; ++j) {
            total += grades[i][j];
        }
        
        //Calculate the average exam grade for the student and print it
        average = (double)total/tests;
        printf("The average grade for student %lu is %.2lf\n", i+1, average);
    }

} //End of averages
