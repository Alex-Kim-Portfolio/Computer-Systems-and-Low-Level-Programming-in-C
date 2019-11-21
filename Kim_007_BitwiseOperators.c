//Alexander Kim
//11.11.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab10 Practicing with Bitwise Operators
//No issues/problems

#include <stdio.h>
#include <stdint.h>

/* weatherlog_t is a "weather sensor log type"
 which is really defined as a 64-bit unsigned
 integer.  See below. */
typedef uint64_t weatherlog_t;

unsigned int add(unsigned int, unsigned int);
unsigned int sub(unsigned int, unsigned int);
unsigned int mul(unsigned int, unsigned int);
void print_half_nybbles(unsigned int);
void reverse_half_nybbles(unsigned int);
int has_odd(unsigned int);
unsigned int make_odd(unsigned int);
int is_negative(int);
weatherlog_t pack_log_entry(unsigned int, unsigned int, unsigned int,
                            unsigned int,
                            int, int,
                            unsigned int, unsigned int);
unsigned int get_year(weatherlog_t entry);
unsigned int get_month(weatherlog_t entry);
unsigned int get_day(weatherlog_t entry);
unsigned int get_zip(weatherlog_t entry);
unsigned int get_high(weatherlog_t entry);
unsigned int get_low(weatherlog_t entry);
unsigned int get_precip(weatherlog_t entry);
unsigned int get_wind(weatherlog_t entry);





int main(int argc, char **argv) {
    unsigned int i, j;
    int x, y;
    unsigned int year, month, day,
    zip, high_temp, low_temp, precip, avg_wind_speed;
    weatherlog_t log_entry;
    
    printf("\nEnter an integer: ");
    scanf("%u", &i);
    printf("Enter another integer: ");
    scanf("%u", &j);
    printf("One more integer, please: ");
    scanf("%d", &x);
    printf("Please enter a positive integer: ");
    scanf("%d", &y);
    
    printf("\n========add========");
    printf("\n%d + %d = %u\n", i, j, add(i,j));
    printf("\n========sub========\n");
    printf("%d - %d = %d\n", i, j, sub(i,j));
    printf("\n========mul========\n");
    printf("%d * %d = %u\n\n", i, j, mul(i,j));

    printf("==========is_negative==========");
    if (is_negative(x))
        printf("\n%d is negative\n\n", x);
    else
        printf("\n%d is non-negative\n\n", x);

    printf("===============has_odd & make_odd===============");
    if (has_odd(y)) {
        printf("\n%d (in hex 0x%x) has an odd number of bits in its binary representation\n\n", y, y);
    }
    else {
        printf("\n%d (in hex 0x%x) has an even number of bits in its binary representation\n", y, y);
        printf("but %x has an odd number of bits in its binary representation\n\n", make_odd(y));
    }

    printf("===============print_half_nybbles & reverse_half_nybbles===============");
    printf("\nThe half-nybbles of %d (in hex 0x%x) are: ", x, x);
    print_half_nybbles(x);

    printf("%d (in hex 0x%x) with reversed half-nybbles is: ", x, x);
    reverse_half_nybbles(x);
    
    printf("\n\n");

    printf("===============WEATHERLOG===============");
    //Ask the user for a year and store it.
    printf("\nEnter a year: ");
    scanf("%u", &year);
        
    //Ask the user for a month and store it.
    printf("Enter a month as an integer (1-12): ");
    scanf("%u", &month);

    //Ask the user for a valid day and store it.
    printf("Enter a day as an integer (1-31): ");
    scanf("%u", &day);
    
    //Ask the user for a valid zip code and store it.
    printf("Enter a zip code as an integer (0-99999): ");
    scanf("%u", &zip);

    //Ask the user for temperatures and store them.
    printf("Enter a temperature as an integer: ");
    scanf("%u", &high_temp);

    printf("Enter another temperature as an integer: ");
    scanf("%u", &low_temp);

    //Ask the user for rainfall amount and store it.
    printf("Enter rainfall amount as an integer (mm): ");
    scanf("%u", &precip);

    //Ask the user for a wind speed and store it.
    printf("Enter a wind speed as an integer (km/hr): ");
    scanf("%u", &avg_wind_speed);

    

    //Pack the contents of the variables above into a log_entry.
    log_entry = pack_log_entry(year, month, day, zip, high_temp, low_temp,
                             precip, avg_wind_speed);
    
    //Print out the contents of the weatherlog.
    printf("\nYou entered: %u/%u/%u for zip %5d: high %d F, low %d F, precip %d mm, wind speed %d km/hr\n\n",
           get_day(log_entry), get_month(log_entry), get_year(log_entry),
           get_zip(log_entry), get_high(log_entry), get_low(log_entry),
           get_precip(log_entry), get_wind(log_entry));
    
    return 0;
}//End of main





unsigned int add(unsigned int i, unsigned int j) {
    //i holds running addition result
    //j holds carries
    
    //While there are more places that needs carry overs...
    while(j != 0) {
        //Use & bitwise operator to find which positions need carries/carry overs
        //Find carries/carry positions that need the carry
        int carryBeforeShift = i & j;
        
        //Do the "addition" and store it in i
        //Use ^ bitwise operator to simulate the actual additions of bits
        i = i ^ j;
        
        //Use << bitwise operator to apply the carry to the position 1 to the left
        j = carryBeforeShift << 1;
        
        //In next iteration, add i with j (j now holds the carry)
    }
    
    return i;
}





unsigned int sub(unsigned int i, unsigned int j) {
    //Make j negative by taking the NOT of j, and adding 1. This is j's two's complement which is equivalent to negative j.
    j = add((~j), 1);
    
    //Take i and add it to negative j (same as subtracting j), then assign the new value to i
    i = add(i, j);
    
    return i;
}





unsigned int mul(unsigned int i, unsigned int j) {
    unsigned int result = 0;

    //Add up i, j times. (Ex. 5 * 3 is the same as 5 added up j times.)
    for(unsigned int k = 0; k < j; k = add(k,1)) {

        result = add(result, i);

    }

    return result;
}





/* prints the half-nybbles (i.e. 2 bit values) of x,
 one half-nybble at a time */
void print_half_nybbles(unsigned int x) {
    unsigned int printedHalfNybbles = 0;
    unsigned int numBits = mul(sizeof(x), 8);
    
    //Keeps looping while there are more half nibbles to print sizeof(x) * 4 = number of half-nibbles, while sizeof(x) * 8 = number of bits)
    while(printedHalfNybbles < mul(sizeof(x), 4)) {
        
        //Shifts the most significant bit to the least significant bit's place, and prints the bit now in the least significant bit place.
        //Then shifts the most significant bit to the second least significant bit's place, and prints the value to the right of the second least significant bit.
        //Togther, these print a half-nibble.
        printf("%d%d", x >> sub(numBits, 1), (x >> sub(numBits, 2)) & 1);
        
        //Puts a space between each half-nibble.
        printf(" ");
        
        //Take x and shift it two to the left.
        x = x << 2;
        
        //Increment the number of half nibbles printed.
        printedHalfNybbles = add(printedHalfNybbles, 1);
    }
    
    printf("\n");
}





/* returns the reverse of the half-nybbles of i */
void reverse_half_nybbles(unsigned int i) {
    unsigned int printedHalfNybbles = 0;
    unsigned int reversedHalfNybbles = 0;
    unsigned int numBits = mul(sizeof(i), 8);
    
    //Loop while the number of printed half nibbles is less than one less than the number of half-nibbles needed
    while(printedHalfNybbles < sub(mul(sizeof(i), 4), 1)) {
        
        //XOR the last two bits in i (to isolate them), and store it in reversedHalfNybbles.
        reversedHalfNybbles = reversedHalfNybbles ^ (i & 3);
        
        //Shift reversedHalfNybbles to the left by 2 to allow room for the next half-nibble of i.
        reversedHalfNybbles = reversedHalfNybbles << 2;
        
        //Shift i to the left by 2 to prepare for storing the next half-nibble in reversedHaldNybble.
        i = i >> 2;
        
        //Increment the number of half-nibbles printed
        printedHalfNybbles = add(printedHalfNybbles, 1);
    }
    
    //On the last half-nibble, do not shift reversedHalfNybbles after XOR, so that we don't lose data. Only shift i.
    reversedHalfNybbles = reversedHalfNybbles ^ (i & 3);
    i = i >> 2;
    
    printedHalfNybbles = 0;
    
    //Keeps looping while there are more half nibbles to print sizeof(x) * 4 = number of half-nibbles, while sizeof(x) * 8 = number of bits)
    while(printedHalfNybbles < mul(sizeof(reversedHalfNybbles), 4)) {
        
        //Shifts the most significant bit to the least significant bit's place, and prints the bit now in the least significant bit place.
        //Then shifts the most significant bit to the second least significant bit's place, and prints the value to the right of the second least significant bit.
        //Togther, these print a half-nibble.
        printf("%d%d", reversedHalfNybbles >> sub(numBits, 1), (reversedHalfNybbles >> sub(numBits, 2)) & 1);
        
        //Puts a space between each half-nibble.
        printf(" ");
        
        //Take x and shift it two to the left.
        reversedHalfNybbles = reversedHalfNybbles << 2;
        
        //Increment the number of half nibbles printed.
        printedHalfNybbles = add(printedHalfNybbles, 1);
    }
    
    printf("\n");

}





/* returns 1 if x < 0
 returns 0 otherwise */
int is_negative(int x) {
    int result = 0;
    
    //0x80000000(HEX) is the largest value of an int (equivalent of 2147483648 in decimal form, and is equivalent to 1 with 31 0's after it (in 32 bit system)).
    //Take the & of 0x80000000 and x. Since positive numbers have the most significant bit set as 0, the result of this operation will always be 0.
    if((x & 0x80000000) == 0) {
        result = 0;
    } else {
        result = 1;
    }
    
    return result;
}





/* returns 1 if x's binary representation
 has an odd number of 1s or 0 otherwise */
int has_odd(unsigned int x) {
    unsigned int numBits = mul(sizeof(x), 8);
    unsigned int visitedBits = 0;
    unsigned int numOfOnes = 0;
    
    //Visit each bit in the while loop
    while(visitedBits < numBits) {
        
        //Shift the most significant bit down to the least significant bit's place
        if(((x >> sub(numBits, 1)) & 1) == 1) {
            //If that bit is 1, then increment the count of ones found in the bit string
            numOfOnes = add(numOfOnes, 1);
        }
        
        //Shift x down 1 bit to the left and do the process over again
        x = x << 1;
        
        //Increment the number of bits visited
        visitedBits = add(visitedBits, 1);
    }
    
    //Return the appropriate value depending on whether the number of ones in the bit string is even or odd
    if(numOfOnes & 1) {
        return 1;
    } else {
        return 0;
    }
}





/* If x's binary representation contains an odd number of 1s, x is
 returned. Otherwise, it returns a copy of x, but with its most significant
 bit modified so that there is an odd number of 1s. */
unsigned int make_odd(unsigned int x) {
    
    //0x80000000(HEX) is the largest value of an int (equivalent of 2147483648 in decimal form, and is equivalent to 1 with 31 0's after it (in 32 bit system)).
    //The XOR operation will flip the very first bit (most significant bit) of x from 0 to 1.
    if(!has_odd(x)) {
        x = x ^ 0x80000000;
    }
    
    return x;
}





/* combines all of the arguments into a single weatherlog_t entry as described below */
weatherlog_t pack_log_entry(unsigned int year, unsigned int month, unsigned int day,
                            unsigned int zip, int high_temp, int low_temp,
                            unsigned int precip, unsigned int avg_wind_speed) {
    //Initialize the variable entry of type weatherlog_t
    weatherlog_t entry = 0;
    
    //Subtract 2000 from entered year and add it to the entry variable
    year = sub(year, 2000);
    entry = entry ^ (year & 63);
    
    //Shift entry 4 bits to the left to make room for the bits in month to be stored in entry. Store month in entry.
    entry = entry << 4;
    entry = entry ^ (month & 15);
    
    //Shift entry 5 bits to the left to make room for the bits in day to be stored in entry. Store day in entry.
    entry = entry << 5;
    entry = entry ^ (day & 31);
    
    //Shift entry 16 bits to the left to make room for the bits in zip to be stored in entry. Store zip in entry.
    entry = entry << 16;
    entry = entry ^ (zip & 65535);
    
    //Makes sure that the highest entry is always printed before the lowest entry (AKA the case where the user enters a low temp before a high temp)
    if(high_temp < low_temp) {
        //Shift entry by 8 bits to the left and store low temp in entry
        entry = entry << 8;
        entry = entry ^ (low_temp & 255);
        //Shift entry by 8 bits to the left and store high temp in entry
        entry = entry << 8;
        entry = entry ^ (high_temp & 255);
    } else {
        //Shift entry by 8 bits to the left and store high temp in entry
        entry = entry << 8;
        entry = entry ^ (high_temp & 255);
        //Shift entry by 8 bits to the left and store low temp in entry
        entry = entry << 8;
        entry = entry ^ (low_temp & 255);
    }
    
    //Shift entry by 10 bits to the left to make room for the bits in precip to be stored in entry. Store precip in entry.
    entry = entry << 10;
    entry = entry ^ (precip & 1023);
    
    //Shift entry by 7 bits to the left to make room for the bits in avg_wind_speed to be stored in entry. Store avg_wind_speed in entry.
    entry = entry << 7;
    entry = entry ^ (avg_wind_speed & 127);
    
    //Return entry
    return entry;
}

/* weatherlog_t

A particular weather sensor called the WeatherJuicer 2000 TM stores a
log entry each day, representing weather activity from the
previous 24 hours. Each entry includes a:

- year :: 6 bits -- stored as the number of years since the year 2000.
- month :: 4 bits
- day :: 5 bits
- zip_code :: 16 bits
- high_temp :: in degrees Fahrenheit, stored as an 8-bit signed integer
- low_temp :: in degrees Fahrenheit, stored as 8-bit signed integer
- precipitation :: in mm. stored as a 10-bit unsigned integer.
- average_wind_speed :: 7 bits. unsigned int km/hr.

All of these are packed into a 64 bit unsigned integer in the above order.

For example, if on September 16, 2015, on Temple's main campus, which
is in zip code 19122, we have 15 mm of rain, a high temperature of 85
degrees, a low temperature of 65 degrees, and an average wind speed of
5 km/hour.

We'd store:
- year :: 2015, which is 15 years from 2000, so 001111
- month :: September, which is the 9th month, so 1001.
- day :: 16, which is 1 0000
- zip_code :: 19122 which is 0100 1010 1011 0010
- high_temp :: 85F, so 0101 0101
- low_temp :: 65F, so 0100 0001
- precipitation :: 35 mm so 00 0010 0011
- average wind speed :: 5 km/h, so 000 0101

And all would be packed into a single 64-bit unsigned integer:

00 1111 1001 10000 0100 1010 1011 0010 0101 0101 0100 0001 00 0010 0011 000 0101

OR

0011 1110 0110 0000 1001 0101 0110 0100 1010 1010 1000 0010 0001 0001 1000 0101

OR

0x3e609564aa821185


We define this weather log as its own datatype called weatherlog_t, which
under the covers is really a 64-bit unsigned int. This is done in the line:

typedef uint64_t weatherlog_t;

*/




unsigned int get_year(weatherlog_t entry) {
    //Shift 58 to the right because year is represented by the first 6 significant bits (64-58 = 6).
    entry = entry >> 58;
    
    return entry;
}





unsigned int get_month(weatherlog_t entry) {
    //15 = 0xf = 1111. Bit masking to get the 4 bits in entry that represent month.
    entry = (entry >> 54) & 15;
    
    return entry;
}





unsigned int get_day(weatherlog_t entry) {
    //31 = 0x1f = 11111. Bit masking to get the 5 bits in entry that represent day.
    entry = (entry >> 49) & 31;
    
    return entry;
}





unsigned int get_zip(weatherlog_t entry) {
    //65535 = 0xffff = 1111111111111111. Bit masking to get the 16 bits in entry that represent zip.
    entry = (entry >> 33) & 65535;
    
    return entry;
}





unsigned int get_high(weatherlog_t entry) {
    //255 = 0xff = 11111111. Bit masking by 255 to get the 8 bits in entry that represent high_temp.
    entry = (entry >> 25) & 255;
    
    //Initialize a signed 8 bit int to 0.
    int8_t result = 0;

    //If the most significant bit in entry is 1 (meaning the value is negative)...
    if(entry >> 8){
        //Result is equal to an 8 bit int with negative representation of entry.
        result = (~result) & entry;
    } else {
        result = entry;
    }
    
    return result;
}





unsigned int get_low(weatherlog_t entry) {
    //255 = 0xff = 11111111. Bit masking by 255 to get the 8 bits in entry that represent low_temp.
    entry = (entry >> 17) & 255;
    
    //Initialize a signed 8 bit int to 0.
    int8_t result = 0;

    //If the most significant bit in entry is 1 (meaning the value is negative)...
    if(entry >> 8){
        //Result is equal to an 8 bit int with negative representation of entry.
        result = (~result) & entry;
    } else {
        result = entry;
    }
    
    return result;
}





unsigned int get_precip(weatherlog_t entry) {
    //1023 = 0x3ff = 1111111111. Bit masking to get the 10 bits in entry that represent precip.
    entry = (entry >> 7) & 1023;
    
    return entry;
}





unsigned int get_wind(weatherlog_t entry) {
    //127 = 0x7f = 1111111. Bit masking to get the 7 bits in entry that represent the avg_wind_speed.
    entry = entry & 127;
    
    return entry;
}
