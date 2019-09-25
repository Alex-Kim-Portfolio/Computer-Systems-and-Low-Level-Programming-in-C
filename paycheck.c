//Alexander Kim
//9/3/19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab02 Paycheck
//No issues/problems, the program compiles and runs.

//Tell the preprocessor to go and include source code from these files to use in this program.
#include <stdio.h>
#include <stdlib.h>

int main() {
    //Print welcoming message and declare variables.
    printf("Welcome to \"TEMPLE HUMAN RESOURCES\"\n\n");

    long employeeNumber;
    double hourlySalary;
    double regularPay;
    double overtimePay;
    double netPay;
    double weeklyTime;

    //Ask the user for Employee number. Return error message and exit the program if invalid input is entered.
    printf("\tEnter Employee Number: ");
    scanf("%ld", &employeeNumber);

    if(employeeNumber <= 0) {
        printf("\n\tThis is not a valid Employee Number.\n\tPlease run the program again.\n\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        return 0;
    }

    //Ask the user for hourly salary. Return error message and exit the program if invalid input is entered.
    printf("\tEnter Hourly Salary: ");
    scanf("%lf", &hourlySalary);

    if(hourlySalary <= 0) {
        printf("\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again.\n\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        return 0;
    }
        
    //Ask the user for weekly time. Weekly time may be zero, since someone can choose to work 0 hours. Return error message and exit the program if invalid input is entered.
    printf("\tEnter Weekly Time: ");
    scanf("%lf", &weeklyTime);

    if(weeklyTime < 0) {
        printf("\n\tThis is not a valid weekly time.\n\tPlease run the program again.\n\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        return 0;
    }
    
    //Calculate overtime pay if weekly time is over 40 hours. Overtime pay is 1.5 * regular salary, for every hour over 40 hours.
    if(weeklyTime > 40) {
        regularPay = 40 * hourlySalary;
        overtimePay = (1.5 * hourlySalary) * (weeklyTime - 40);
        netPay = regularPay + overtimePay;
    } else {
        netPay = weeklyTime * hourlySalary;
    }
    
    //Print results and use format specifiers as needed.
    printf("\t===================================\n");
    printf("\tEmployee #: %ld\n", employeeNumber);
    printf("\tHourly Salary: $%.2lf\n", hourlySalary);
    printf("\tWeekly Time: %.2lf\n", weeklyTime);
    printf("\tRegular Pay: $%.2lf\n", regularPay);
    printf("\tOvertime Pay: $%.2lf\n", overtimePay);
    printf("\tNet Pay: $%.2lf\n", netPay);
    printf("\t===================================\n\n");
    
    //Print closing message.
    printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
    
    //Exit the program.
    return 0;
    
}
