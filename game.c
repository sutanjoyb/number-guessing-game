#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    srand(time(NULL));

    int guess, tries, answer, min, max, difficulty;
    char playAgain;

    do
    {

        tries = 0;
        min = 1;

        printf("\n*** NUMBER GUESSING GAME ***\n");
        printf("Select Difficulty:\n1. Easy (1-50)\n2. Medium (1-100)\n3. Hard (1-500)\nChoice: ");
        scanf("%d", &difficulty);

        if (difficulty == 1)
            max = 50;
        else if (difficulty == 3)
            max = 500;
        else
            max = 100;

        answer = (rand() % (max - min + 1)) + min;

        do
        {
            printf("Guess a number (%d - %d): ", min, max);

            if (scanf("%d", &guess) != 1)
            {
                printf("Invalid input! Please enter a number.\n");
                while (getchar() != '\n')
                    ;
                continue;
            }

            tries++;

            if (guess < answer)
            {
                printf("TOO LOW!\n");
            }
            else if (guess > answer)
            {
                printf("TOO HIGH!\n");
            }
            else
            {
                printf("\nCORRECT!\n");
                printf("The answer was %d and it took %d attempts to guess.\n", answer, tries);
            }

        } while (guess != answer);

        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &playAgain);

    } while (toupper(playAgain) == 'Y');

    printf("\nThanks for playing! Goodbye.\n");

    return 0;
}