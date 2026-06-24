// WAP to count words in a scentence
#include <stdio.h>
void main() {
    char str[100];
    int i, words = 1; // Start with 1 word

    printf("Enter a sentence: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return;
    }

    // Count words by counting spaces
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0') {
            words++;
        }
    }

    printf("Number of words in the sentence: %d\n", words);
}