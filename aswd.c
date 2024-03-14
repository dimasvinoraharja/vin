#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10
#define MIN_LENGTH 7

void lessThanRequired(int* lengthOfText) {
    printf("The length of your text is less than specified, please update your text\n");
    *lengthOfText = MIN_LENGTH;
}

void equalThanRequired(int* lengthOfText) {
    printf("Thank you, Your text length is correct\n");
    (void)lengthOfText; // To suppress unused parameter warning
}

void moreThanRequired(int* lengthOfText) {
    printf("Your text is too long, please reduce the text\n");
    *lengthOfText = MIN_LENGTH;
}

int checkLengthRequirement(char* text) {
    int length = strlen(text);
    if (length < MIN_LENGTH)
        return 0;
    else if (length == MIN_LENGTH)
        return 1;
    else
        return 2;
}

int main() {
    int lengthOfText = 0, selectOption;
    FILE* fptr = NULL;
    char text[MAX_LENGTH];

    fptr = fopen("file.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fgets(text, MAX_LENGTH, fptr);
    fclose(fptr);

    selectOption = checkLengthRequirement(text);

    // Function pointers
    void (*functionArray[3])(int*) = {lessThanRequired, equalThanRequired, moreThanRequired};
    functionArray[selectOption](&lengthOfText);

    printf("\nThe Length is updated to %d", lengthOfText);

    return 0;
}
