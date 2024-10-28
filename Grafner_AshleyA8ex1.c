//Ashley Grafner
//10/22/2024

//Question 1:
//Creates an array of strings and uses pointers to check if the string has;
// All uppercase, all lowercase, or mixture
//Will display the pointer address for each string, string value, and category
//Use string functions from string.h

#include <stdio.h>
#include <string.h>

    void categorizeString(char *str) {
        // Define sets of uppercase and lowercase characters
        const char *upper_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //capitals
        const char *lower_chars = "abcdefghijklmnopqrstuvwxyz"; //lowercase

        // Check for the presence of uppercase and lowercase characters
        // strpbrk will search for the first occurrence of any character from the array
        // If it finds any (upper/lower), it returns a pointer to the first occurrence; otherwise, it returns NULL.
        int count_upper = (strpbrk(str, upper_chars) != NULL);
        int count_lower = (strpbrk(str, lower_chars) != NULL);

        // Print the category based on the presence of uppercase and lowercase characters
        if (count_upper && count_lower) {
            printf("Category: Mix of upper and lowercase\n");
        } else if (count_upper) {
            printf("Category: All uppercase\n");
        } else if (count_lower) {
            printf("Category: All lowercase\n");
        }
    }


int main(void) {
    // Create an array of strings:
    char *stringsArray[] = { "Ashley Grafner", "ashley", "ASHLEY", "ashley grafner", "aSHleY GraFNeR"};

    // Calculate the number of strings in the array by dividing the total size of the array
    // by the size of an individual string element
    int num_strings = sizeof(stringsArray) / sizeof(stringsArray[0]);

    for (int i = 0; i < num_strings; i++) {  // Loop through each string in the array

        printf("\nPointer address: %p\n", (void*)stringsArray[i]); // Print the memory address of string
        printf("String value: %s\n", stringsArray[i]);  //print the string value

        // Call the function categorizeString to classify the current string (category type):
        categorizeString(stringsArray[i]);
    }
    return 0;
}