//Alexander Kim
//10.3.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab06 Race
//No issues/problems, the program compiles and runs.

//Include libraries and define constants
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define RAND_MIN 1
#define RAND_MAX 10

//Function prototypes
void tortMove(int *tortPos, char tortMoveType[]);
void hareMove(int *harePos, char hareMoveType[]);
void displayRace(int *tortPos, int *harePos);

//Main function
int main() {
    
    //Initialize tortoise and hare position
    int tortPos = 1;
    int harePos = 1;
    
    //Initialize variable to keep track of turn number
    int turn = 1;
    
    //Create an array of characters to store a String identifying the type of move for both the tortoise and hare
    char tortMoveType[12];
    char hareMoveType[12];
    
    //Pass the rand function a seed (internal clock) to generate real randomized numbers
    srand((unsigned)time(NULL));
    
    //Keep performing the loop as long as the tortoise and hare have not reached the 70th square
    while (tortPos < 70 && harePos < 70) {
        //Create a loop that assigns a different random number for both the tortoise and the hare
        for(int j = 0; j < 2; ++j) {
            if (j==0) {
                int i = rand() % (RAND_MAX + 1) + RAND_MIN;
                         
                if(i >= 1 && i <= 5) {
                    strcpy(tortMoveType, "Fast plod");
                } else if(i >= 6 && i <= 7) {
                    strcpy(tortMoveType, "Slip");
                } else if(i >= 8 && i <= 10) {
                    strcpy(tortMoveType, "Slow plod");
                }
            } else {
                int i = rand() % (RAND_MAX + 1) + RAND_MIN;
                
                if(i >= 1 && i <= 2) {
                    strcpy(hareMoveType, "Sleep");
                } else if(i >= 3  && i <= 4) {
                    strcpy(hareMoveType, "Big hop");
                } else if(i == 5) {
                    strcpy(hareMoveType, "Big slip");
                } else if(i >= 6 && i <= 8) {
                    strcpy(hareMoveType, "Small hop");
                } else if (i >= 9 && i <= 10) {
                    strcpy(hareMoveType, "Small slip");
                }
            }
        }
        
        //Print the appropriate statement and make the appropriate movement depending on the location of the tortoise and the hare
        if(turn == 1) {
            printf("BANG !!!!!\nAND THEY'RE OFF !!!!!\n");
        } else {
            tortMove(&tortPos, tortMoveType);
            hareMove(&harePos, hareMoveType);
            
            if(tortPos <= 0) {
                tortPos = 1;
            } else if (harePos <= 0) {
                harePos = 1;
            }
            
            if(tortPos >= 70 && harePos <= 70) {
                displayRace(&tortPos, &harePos);
                break;
            } else if(harePos >= 70 && tortPos <= 70) {
                displayRace(&tortPos, &harePos);
                break;
            } else {
                displayRace(&tortPos, &harePos);
            }
        }
        
        //Increment the turn number to keep track
        turn++;
        
        //Pause the program to see the program happen in real time
        sleep(1);
    }//End of while loop
}//End of main


//This function takes the tortoise position and tortoise move type
void tortMove(int *tortPos, char tortMoveType[]) {
    
    //Depending on the type of move, increment or decrement the tortoise position by the appropriate amount
    if ((strcmp(tortMoveType, "Fast plod")) == 0) {
        *tortPos = *tortPos + 3;
    } else if ((strcmp(tortMoveType, "Slip")) == 0) {
        *tortPos = *tortPos - 6;
    } else if ((strcmp(tortMoveType, "Slow plod")) == 0) {
        *tortPos = *tortPos + 1;
    }

}//End of tortMove


//This function takes the hare position and hare move type
void hareMove(int *harePos, char hareMoveType[]) {
    
    //Depending on the type of move, increment or decrement the hare position by the appropriate amount
    if ((strcmp(hareMoveType, "Sleep")) == 0) {
        *harePos = *harePos;
    } else if ((strcmp(hareMoveType, "Big hop")) == 0) {
        *harePos = *harePos + 9;
    } else if ((strcmp(hareMoveType, "Big slip")) == 0) {
        *harePos = *harePos - 12;
    } else if ((strcmp(hareMoveType, "Small hop")) == 0) {
        *harePos = *harePos + 1;
    } else if ((strcmp(hareMoveType, "Small slip")) == 0) {
        *harePos = *harePos - 2;
    }

}//End of hareMove


//This function displays the appropriate message or the position of the tortoise and the hare
void displayRace(int *tortPos, int *harePos) {
    //Print the appropriate message depending on the position of the tortoise and the hare, and their current positions
    if (*tortPos == *harePos) {
        printf("OUCH !!!\n");
    } else if(*tortPos >= 70 && *harePos >= 70) {
        printf("It's a tie\n");
    }else if (*tortPos >= 70 && *harePos < 70) {
        printf("TORTOISE WINS!!! YAY!!\n");
    } else if (*harePos >= 70 && *tortPos < 70) {
        printf("Hare wins. Yuch.\n");
    } else {
        char *tortPrint = "T";
        char *harePrint = "H";
        
        if(*tortPos > *harePos) {
            printf("%*s%s%*s%s\n", *harePos, "", harePrint, (*tortPos - *harePos), "", tortPrint);
        } else if (*harePos > *tortPos) {
            printf("%*s%s%*s%s\n", *tortPos, "", tortPrint, (*harePos - *tortPos), "", harePrint);
        }
    }
    
}//End of displayRace


