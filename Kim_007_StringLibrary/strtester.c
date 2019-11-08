//Alexander Kim
//10.29.19
//CIS 2107-007 (Lab: Tue 11-12:50; Lec: Tue, Thu 3:30-4:50)
//Lab09 String Library
//No issues/problems

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "alex_kim_string_library.h"

int main() {
    //Testing all_letters
    printf("%d\n", all_letters("Hello World"));
    printf("%d\n\n", all_letters("Hell0 World"));

    //Testing num_in_range
    printf("%d\n\n", num_in_range("Yellow", 'f', 'm'));

    //Testing diff
    printf("%d\n\n", diff("Book", "Back"));

    //Testing shorten
    shorten("Hello World", 5);
    shorten("Hello World", 20);
    printf("\n");

    //Testing len_diff
    printf("%d\n\n", len_diff("Philadelphia", "Hello"));

    //Testing rm_left_space
    rm_left_space("    Hello");
    printf("\n");

    //Testing rm_right_space
    rm_right_space("Hello    ");
    printf("\n\n");

    //Testing rm_space
    rm_space("   Hello   ");
    printf("\n\n");

    //Testing find
    printf("%d\n", find("Hello", "l"));
    printf("%d\n\n", find("Hello", "q"));

    //Testing ptr_to
    printf("%p\n", ptr_to("Hello", "l"));
    printf("%s\n\n", ptr_to("Hello", "q"));

    //Testing is_empty
    printf("%d\n", is_empty(" "));
    printf("%d\n\n", is_empty("Hello"));

    //Testing str_zip
    printf("%s\n\n", str_zip("Temple", "Hello"));

    //Testing capitalize
    capitalize("hello world");
    printf("\n");

    //Testing strcmp_ign_case
    printf("%d\n", strcmp_ign_case("hello", "goodbye"));
    printf("%d\n\n", strcmp_ign_case("Hello", "hello"));

    //Testing take_last
    take_last("hello", 3);
    take_last("hello", 6);
    printf("\n");

    //Testing dedup
    printf("%s\n\n", dedup("hello"));

    //Testing pad
    printf("\"%s\"\n", pad("hello", 6));
    printf("\"%s\"\n\n", pad("hello", 5));

    //Testing ends_with_ignore_case
    printf("%d\n", ends_with_ignore_case("Coding", "ing"));
    printf("%d\n\n", ends_with_ignore_case("Coding", "ed"));

    //Testing repeat
    printf("%s\n\n", repeat("hello", 3, '-'));

    //Testing replace
    printf("%s\n\n", replace("Steph is the X", "X", "best"));

    //Testing str_connect
    printf("%s\n\n", str_connect("Hello world Hello world", 4, '-'));

    //Testing rm_empties
    char *array[] = {"Hello", "World", " ", " ", "Steph", NULL};
    rm_empties(array);

    //Testing str_chop_all
    char **result = str_chop_all("Hello/world/hello/world", '/');

    while(*(result + 1) != NULL) {
        printf("%s, ", *result);
        
        result++;
    }
    
    printf("%s", *result);
    
    printf("\n\n");

    return 0;
}
