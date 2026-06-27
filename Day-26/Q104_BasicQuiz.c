#include <stdio.h>
#include <ctype.h>

int main() {
    char answer;
    int score = 0;

    printf("===== Simple Quiz =====\n");

    // Question 1
    printf("\nQ1: What is the capital of India?\n");
    printf("A. New Delhi\nB. Mumbai\nC. Kolkata\nD. Chennai\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (toupper(answer) == 'A') score++;

    // Question 2
    printf("\nQ2: Which language is this quiz written in?\n");
    printf("A. Python\nB. C\nC. Java\nD. C++\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (toupper(answer) == 'B') score++;

    // Question 3
    printf("\nQ3: Which planet is known as the Red Planet?\n");
    printf("A. Earth\nB. Mars\nC. Jupiter\nD. Venus\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (toupper(answer) == 'B') score++;

    // Final score
    printf("\nYour score: %d/3\n", score);
    printf("===== End of Quiz =====\n");

    return 0;
}
