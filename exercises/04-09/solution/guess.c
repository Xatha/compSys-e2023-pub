#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "string.h"

int isNumber(char* string);

int main(void) {
    srand(time(NULL));

    int correctNum = rand() % 10;
    int guessedNum = -1;

    char input[20];

    printf("Please guess a number.\n");

    while (guessedNum != correctNum) {
        scanf("%19s", input);

        if (isNumber(input)) {
            if (sscanf(input, "%d", &guessedNum) == 1) {
                if (guessedNum > correctNum) {
                    printf("Too high!\n");
                } else if (guessedNum < correctNum) {
                    printf("Too Low!\n");
                } else {
                    printf("You guessed correctly!\n");
                    return 0;
                }
            }
        } else {
            printf("You did not input a number!\n");
        }
        printf("Please guess again!\n");
    }
    return 0;
}

int isNumber(char* string) {
    if (strspn(string, "0123456789") == strlen(string)) {
        return 1;
    }
    return 0;
}
