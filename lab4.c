#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10

void playGame();
void displayGuesses(int *guesses, int attempts); // Function to display all guesses

int main() {
    srand(time(0)); // Seed the random number generator
    char playAgain;

    do {
        playGame();
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

void playGame() {
    int number = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    // Declare an array to store guesses

    int guesses[MAX_ATTEMPTS];

    // Declare a pointer to manipulate guesses

    int *pointToGuess = guesses;

    printf("Guess the number between 1 and 100:\n");

    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d: ", attempts + 1);
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Please enter a number between 1 and 100.\n");
            continue;
        }

        // Store the guess in the array using the pointer

        *(pointToGuess + attempts) = guess;

        attempts++;

        if (guess < number) {
            printf("Too low!\n");
        } else if (guess > number) {
            printf("Too high!\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            // Display all guesses
            displayGuesses(guesses, attempts);
            return;
        }
    }

    printf("Sorry, you've used all %d attempts. The number was %d.\n", MAX_ATTEMPTS, number);
    // Display all guesses
    displayGuesses(guesses, attempts);
}

// Function to display all guesses
void displayGuesses(int *guesses, int attempts) {
    printf("Previous guesses:");
    for (int i = 0; i < attempts; i++) {
        printf("%d ", guesses[i]);
    }
}