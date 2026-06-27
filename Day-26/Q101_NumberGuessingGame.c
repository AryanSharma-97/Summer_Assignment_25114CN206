// WAP to make a number guessing game
#include <stdio.h>
#include <stdlib.h>

int main() {
    int low = 1, high = 100, mid;
    char response;

    printf("Think of a number between %d and %d.\n", low, high);
    printf("I will try to guess it using binary search.\n");
    printf("Respond with:\n");
    printf("  'h' if my guess is too high\n");
    printf("  'l' if my guess is too low\n");
    printf("  'c' if my guess is correct\n\n");

    while (low <= high) {
        mid = low + (high - low) / 2; // Avoid overflow
        printf("Is your number %d? (h/l/c): ", mid);

        // Read user input safely
        if (scanf(" %c", &response) != 1) {
            printf("Invalid input. Please enter 'h', 'l', or 'c'.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        if (response == 'c' || response == 'C') {
            printf("Yay! I guessed your number %d correctly!\n", mid);
            break;
        } 
        else if (response == 'h' || response == 'H') {
            high = mid - 1;
        } 
        else if (response == 'l' || response == 'L') {
            low = mid + 1;
        } 
        else {
            printf("Invalid choice! Please enter 'h', 'l', or 'c'.\n");
        }
    }

    if (low > high) {
        printf("Hmm... It seems there was a misunderstanding in your responses.\n");
    }

    return 0;
}
