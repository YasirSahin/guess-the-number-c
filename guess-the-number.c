#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void guessTheNumber() {
    srand(time(NULL));
    int number = rand() % 100 + 1;
    int guess;
    int attempts = 10;
    int score = 100;

    printf("Guess a number between 1 and 100. You have 10 attempts.\n");

    while (attempts > 0) {
        printf("Guess: ");
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter only a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (guess < 0 || guess > 100) {
            printf("Please enter a number between 0 and 100.\n");
            continue;
        }

        if (guess > number) {
            printf("Lower\n");
        } else if (guess < number) {
            printf("Higher\n");
        } else {
            printf("Correct! Your score: %d\n", score);
            break;
        }

        attempts--;
        score -= 10;

        if (attempts == 0) {
            char retry;
            printf("Out of attempts. Do you want to play again? (y/n): ");
            scanf(" %c", &retry);
            if (retry == 'y') {
                printf("\n");
                guessTheNumber();
            } else {
                break;
            }
        }
    }
}

int main() {
    guessTheNumber();
    return 0;
}
