//Alexander Kim
//9.10.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab03 ATM
//No issues/problems, the program compiles and runs.


//Tell the preprocessor to go and include source code from these files to use in this program.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


//Declare function prototypes.
void checkBalance(double *balance);
void cashWithdrawal(double *balance, double *withdrawTotal);
void cashDeposition(double *balance, double *depositTotal);
int quit(int *transactions);

/************************************************
 Main Function: No parameters. Runs the program.
************************************************/
int main() {
    
    //Declare and instantiate needed variables
    const int PIN = 3014;
    int numAttemptsRemaining = 3;
    int transactions = 0;
    double balance = 5000;
    double withdrawTotal = 0;
    double depositTotal = 0;
    bool userContinuesUsing = true;
    bool continueLoop = false;
    
    //Print welcome statement and ask for PIN number.
    printf("\n\n=================================================================\n");
    printf("Welcome to the ATM. Please enter your four digit PIN number: ");

    //Check to see if the PIN number is correct. User has three attempts. When number of attempts reaches 0, display and error message and exit the program.
    while(numAttemptsRemaining > 0) {
        
        double enteredPin;
        
        scanf("%lf", &enteredPin);
        
        if(enteredPin > 0 && enteredPin == PIN && (fmod(enteredPin, 1) == 0)) {
            printf("\n\nSuccess! Loading...\n");
            break;
        } else {
            numAttemptsRemaining--;
            if(numAttemptsRemaining == 0) {
                break;
            }
            printf("\nInvalid PIN. You currently have %d attempt(s) remaining. Please enter your four digit PIN number again: ", numAttemptsRemaining);
        }
    }
    
    if(numAttemptsRemaining == 0) {
        printf("\nToo many PIN attempts. Exiting the system. Have a good day!\n");
        return 0;
    }
    
    //Present menu options, read in user input and depending on the input, call the appropriate method or show an appropriate error message.
    do {

        do {
            //Reset this variable every time the loop iterates.
            //If one of the if/else statements sets this loop to true, it will continue to loop until the user enters 4 (without asking if they want another transaction). Want to avoid this.
            continueLoop = false;
            
            printf("\n\n============================================================================\n");
            printf("Please choose from the following menu by entering the corresponding number.\n\t1 - Check Balance\n\t2 - Withdraw\n\t3 - Deposit\n\t4 - Exit\nEnter your number here: ");
            
            double enteredMenuOption;
    
            scanf("%lf", &enteredMenuOption);
        
            //Present the menu options. Check to make sure limits are not met or exceeded before calling the method.
            if((enteredMenuOption == 1 || enteredMenuOption == 2 || enteredMenuOption == 3 || enteredMenuOption == 4) && (fmod(enteredMenuOption, 1) == 0)) {
                if(enteredMenuOption == 1) {
                    checkBalance(&balance);
                    transactions++;
                } else if (enteredMenuOption == 2) {
                    if(withdrawTotal < 1000) {
                        cashWithdrawal(&balance, &withdrawTotal);
                        transactions++;
                    } else {
                        continueLoop = true;
                        printf("\n\nYou have met or exceeded the daily withdrawal limit of $1000. You may not withdraw more money.");
                    }
                } else if (enteredMenuOption == 3) {
                    if(depositTotal < 10000) {
                        cashDeposition(&balance, &depositTotal);
                        transactions++;
                    } else {
                        continueLoop = true;
                        printf("\n\nYou have met or exceeded the daily deposit limit of $10000. You may not deposit more money.");
                    }
                } else {
                    quit(&transactions);
                    return 0;
                }
            } else {
                continueLoop = true;
                printf("\n\nInvalid menu option. Please try again.\n\n");
            }
            
        } while (continueLoop);
        
        //Ask the user if they want another transaction (this happens after method call). If yes, sends them back to the menu options. If no, it exits the program. If invalid input, it shows an error message.
        do {
            printf("\n\n=====================================================================\n");
            printf("Would you like another transaction? Press 1 for \"yes\" or 2 for \"no\": ");
            
            double enteredNumber;
            
            scanf("%lf", &enteredNumber);
            
            if(fmod(enteredNumber, 1) == 0 && (enteredNumber == 1 || enteredNumber == 2)) {
                if(enteredNumber == 1) {
                    userContinuesUsing = true;
                    break;
                } else if (enteredNumber == 2) {
                    userContinuesUsing = false;
                    quit(&transactions);
                    break;
                }
            } else {
                continueLoop = true;
                userContinuesUsing = false;
                printf("\n\nThat is not a valid option. Please try again.");
            }
            
        } while (continueLoop);
        
        
    } while (userContinuesUsing);

}


/*************************************************************************
 checkBalance: Takes in the balance as a parameter and prints the balance.
*************************************************************************/

void checkBalance(double *balance) {
    
    bool validReceiptInput = false;
    
    //Return the current balance
    printf("\n\n===================================\n");
    printf("Your current balance is: $%.2lf\n", *balance);
    printf("===================================\n");
    
    //Ask the customer if they would like a receipt. Do the appropriate action depending on input. If invalid input, as error message is displayed.
    do{
        printf("\n=====================================================================================");
        printf("\nWould you like a receipt for this transaction? Press 1 for \"yes\" and 2 for \"no\": ");
        double decision;
        scanf("%lf", &decision);
        if((fmod(decision, 1) == 0) && (decision == 1 || decision == 2)) {
            if(decision == 1) {
                printf("\nPrinting receipt...");
                break;
            } else {
                break;
            }
        } else {
            validReceiptInput = false;
            printf("\nNot a valid choice. Please choose either 1 or 2.");
        }
    } while (validReceiptInput == false);
}


/***********************************************************************************************************************************************
 cashWithdrawal: Takes in the balance and the total amount withdrawn that day as parameters, and updates the balance and total amount withdrawn.
 Shows the appropriate error message if limits are exceeded or if user inputs are invalid.
************************************************************************************************************************************************/

void cashWithdrawal(double *balance, double *withdrawTotal) {
    
    double withdrawAmount = 0;
    int numAttemptsRemaining = 3;
    bool validReceiptInput = false;
    
    //Ask the user how much they would like to withdraw, scan in input, and calculate and update new balance and total amount withdrawn.
    //If limits are exceeded or input is invalid, print error message. User has three attempts before the program terminates.
    while(numAttemptsRemaining > 0) {
        printf("\n\n=====================================================================================================\n");
        printf("Please enter the amount you would like to withdraw (in multiples of $20, and change is not allowed): ");
        
        scanf("%lf", &withdrawAmount);
        
        if((fmod(withdrawAmount, 20) == 0) && (fmod(withdrawAmount, 1) == 0) && (withdrawAmount <= 1000 && withdrawAmount > 0)) {
            if((withdrawAmount + *withdrawTotal) > 1000) {
                numAttemptsRemaining--;
                printf("\n\nThe daily withdrawal limit is $1000. Please try again.\n");
            } else {
                *balance = *balance - withdrawAmount;
                *withdrawTotal = *withdrawTotal + withdrawAmount;
                printf("\n\n===========================================================================");
                printf("\n\tCurrent amount withdrawn today: $%.2lf\n\tBalance after withdrawal: $%.2lf\n", *withdrawTotal, *balance);
                printf("===========================================================================\n");
                
                //Ask the customer if they would like a receipt. Do the appropriate action depending on input. If invalid input, as error message is displayed.
                do{
                    printf("\n=====================================================================================");
                    printf("\nWould you like a receipt for this transaction? Press 1 for \"yes\" and 2 for \"no\": ");
                    double decision;
                    scanf("%lf", &decision);
                    if((fmod(decision, 1) == 0) && (decision == 1 || decision == 2)) {
                        if(decision == 1) {
                            printf("\nPrinting receipt...");
                            break;
                        } else {
                            break;
                        }
                    } else {
                        validReceiptInput = false;
                        printf("\nNot a valid choice. Please choose either 1 or 2.");
                    }
                } while (validReceiptInput == false);
                
                break;
            }
        } else if(withdrawAmount > 1000) {
            numAttemptsRemaining--;
            printf("\nThe daily withdrawal limit is $1000. Please choose an amount less than this.\n\n");
        } else {
            numAttemptsRemaining--;
            printf("\n\nInvalid withdrawal amount. Withdrawal amounts must not be negative, zero, or change, and must be in multiples of $20. Please try again.\n");
        }
    }
    
    if(numAttemptsRemaining == 0) {
        printf("\n\nToo many withdrawal attempts (3 attempts allowed). Exiting the system. Have a good day!\n");
        exit(0);
    }
}


/***********************************************************************************************************************************************
 cashDeposition: Takes in the balance and the total amount deposited that day as parameters, and updates the balance and total amount deposited.
 Shows the appropriate error message if limits are exceeded or if user inputs are invalid.
************************************************************************************************************************************************/

void cashDeposition(double *balance, double *depositTotal) {
    double depositAmount = 0;
    int numAttemptsRemaining = 3;
    bool validReceiptInput = false;
    
    //Ask the user how much they would like to deposit, scan in input, and calculate and update new balance and total amount deposited.
    //If limits are exceeded or input is invalid, print error message. User has three attempts before the program terminates.
    while(numAttemptsRemaining > 0) {
        printf("\n\n========================================================================================================\n");
        printf("Please enter the amount you would like to deposit. Accepts any paper bills including $1s, $5s, and $10s: ");
        
        scanf("%lf", &depositAmount);
        
        if((fmod(depositAmount, 1) == 0) && (depositAmount <= 10000 && depositAmount > 0)) {
            if((depositAmount + *depositTotal) > 10000) {
                numAttemptsRemaining--;
                printf("\n\nThe daily deposit limit is $10000. Please try again.\n");
            } else {
                *balance = *balance + depositAmount;
                *depositTotal = *depositTotal + depositAmount;
                printf("\n\n===========================================================================");
                printf("\n\tCurrent amount deposited today: $%.2lf\n\tBalance after deposit: $%.2lf\n", *depositTotal, *balance);
                printf("===========================================================================\n");
                
                //Ask the customer if they would like a receipt. Do the appropriate action depending on input. If invalid input, as error message is displayed.
                do{
                    printf("\n=====================================================================================");
                    printf("\nWould you like a receipt for this transaction? Press 1 for \"yes\" and 2 for \"no\": ");
                    double decision;
                    scanf("%lf", &decision);
                    if((fmod(decision, 1) == 0) && (decision == 1 || decision == 2)) {
                        if(decision == 1) {
                            printf("\nPrinting receipt...");
                            break;
                        } else {
                            break;
                        }
                    } else {
                        validReceiptInput = false;
                        printf("\nNot a valid choice. Please choose either 1 or 2.");
                    }
                } while (validReceiptInput == false);
                
                break;
            }
        } else if(depositAmount > 10000) {
            numAttemptsRemaining--;
            printf("\nThe daily deposit limit is $10000. Please choose an amount less than this.\n\n");
        } else {
            numAttemptsRemaining--;
            printf("\n\nInvalid deposit amount. Deposits can accept any combination of bills, but cannot accept change or be 0 (nothing). Please try again.\n\n");
        }
    }
    
    if(numAttemptsRemaining == 0) {
        printf("\n\nToo many deposit attempts (3 atempts allowed). Exiting the system. Have a good day!\n");
        exit(0);
    }
}


/*******************************************************
 quit: Prints thank you message and exits the program.
*******************************************************/

int quit(int *transactions) {
    printf("\nYou had a total of %d transaction(s) during this interaction. Thank you for using this ATM. Have a good day!\n\n", *transactions);
    return 0;
}
