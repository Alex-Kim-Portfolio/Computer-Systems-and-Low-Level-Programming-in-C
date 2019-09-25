//
//  scanExample.c
//  
//
//  Created by Alexander Kim on 9/3/19.
//

#include <stdio.h>

int main()
{
    printf("Hello World\n");
    
    char str1[20], str2[30];
    
    printf("Enter name: ");
    scanf("%s", str1);
    
    printf("Enter your website name: ");
    scanf("%s", str2);
    
    printf("Entered Name: %s\n", str1);
    printf("Entered Website: %s\n", str2);
    
    // -----------------------------------
    int number;
    // printf() dislpays the formatted output
    printf("Enter an integer: ");
    
    // scanf() reads the formatted input and stores them
    scanf("%d", &number);
    
    // printf() displays the formatted output
    printf("You entered: %d\n", number);
    
    if (number <= 0) {
        printf ("Inavlid number");
    }
    
    
    return 0;
}
