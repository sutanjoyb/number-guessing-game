#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    srand(time(NULL));

    int guess, tries, answer, min, max, difficulty;
    const int MAX_TRIES = 5; // Added a constant for the limit
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

        printf("\nYou have %d attempts to find the number!\n", MAX_TRIES);

        do
        {
            printf("\nAttempt %d/%d - Guess a number (%d - %d): ", tries + 1, MAX_TRIES, min, max);

            if (scanf("%d", &guess) != 1)
            {
                printf("Invalid input! Please enter a number.\n");
                while (getchar() != '\n');
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
                printf("The answer was %d and it took %d attempts.\n", answer, tries);
                break; // Exit loop if they win
            }

            // Check if they ran out of tries
            if (tries >= MAX_TRIES && guess != answer)
            {
                printf("\nLOST!! You've used all %d attempts.\n", MAX_TRIES);
                printf("The correct number was: %d\n", answer);
                break; // Exit loop if they lose
            }

        } while (guess != answer);

        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &playAgain);

    } while (toupper(playAgain) == 'Y');

    printf("\nThanks for playing! Goodbye.\n");

    return 0;
}