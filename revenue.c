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
    printf("Welcome to \"Temple\" store\n\n");
    
    double itemPrice;
    long itemQuantity;
    double costBeforeDiscount;
    double discountDecimal;
    double discountPercentage;
    double discountAmount;
    double totalPrice;
    
    //Ask the user for item price. Return error message and exit the program if invalid input is entered.
    printf("\tEnter item price: ");
    scanf("%lf", &itemPrice);
    
    if(itemPrice <= 0) {
        printf("\n\tThis is not a valid item price.\n\tPlease run the program again.\n\n");
        printf("Thank you for using \"Temple\" store\n");
        return 0;
    }
    
    //Ask the user for quantity. Return error message and exit the program if invalid input is entered.
    printf("\tEnter quantity: ");
    scanf("%ld", &itemQuantity);
    
    //If valid item quantity, calculate discount (in decimal form for ease of calculation) depending on number of items.
    if(itemQuantity <= 0) {
        printf("\n\tThis is not a valid quantity order.\n\tPlease run the program again.\n\n");
        printf("Thank you for using \"Temple\" store\n");
        return 0;
    } else if (itemQuantity >= 1 && itemQuantity <= 49) {
        discountDecimal = 0;
    } else if (itemQuantity >= 50 && itemQuantity <= 99) {
        discountDecimal = .10;
    } else if (itemQuantity >= 100 && itemQuantity <= 149) {
        discountDecimal = .15;
    } else {
        discountDecimal = .25;
    }
    
    //Calculate the cost before the discount.
    costBeforeDiscount = itemPrice * itemQuantity;
    
    //Multiply the discount in decimal form by 100 in order to make displaying in results easier.
    discountPercentage = discountDecimal * 100;
    
    //Calculate the dollar amount that is to be discounted.
    discountAmount = discountDecimal * costBeforeDiscount;
    
    //Subtract the discount amount from the cost before discount to get the final/total price.
    totalPrice = costBeforeDiscount - discountAmount;
    
    //Print results and show breakdown. Use format specifiers as needed. 
    printf("\n\tThe item price is: $%.2lf\n", itemPrice);
    printf("\tThe order is: %.1ld item(s)\n", itemQuantity);
    printf("\tThe cost is: $%.2lf\n", costBeforeDiscount);
    printf("\tThe discount is: %.2lf%%\n", discountPercentage);
    printf("\tThe discount amount is: $%.2lf\n", discountAmount);
    printf("\tThe total is: $%.2lf\n\n", totalPrice);
    
    //Print closing message.
    printf("Thank you for using \"Temple\" store\n");
    
    //Exit the program.
    return 0;
}
