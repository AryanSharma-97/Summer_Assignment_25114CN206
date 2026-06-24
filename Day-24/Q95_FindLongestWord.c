// WAP to find the longest word in string
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to find the longest word in a string
void findLongestWord(const char *str, char *longestWord) {
    int maxLen = 0, currentLen = 0;
    char currentWord[100] = "";
    
    for (int i = 0; ; i++) {
        char ch = str[i];

        // Check if character is part of a word (letters or digits)
        if (isalnum((unsigned char)ch)) {
            currentWord[currentLen++] = ch;
        } else {
            // End of a word
            if (currentLen > 0) {
                currentWord[currentLen] = '\0'; // Null-terminate
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    strcpy(longestWord, currentWord);
                }
                currentLen = 0; // Reset for next word
            }
        }

        // End of string
        if (ch == '\0') break;
    }
}

int main() {
    char str[500];
    char longestWord[100] = "";

    printf("Enter a string: ");
    if (!fgets(str, sizeof(str), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline from fgets
    str[strcspn(str, "\n")] = '\0';

    if (strlen(str) == 0) {
        printf("Empty string entered.\n");
        return 0;
    }

    findLongestWord(str, longestWord);

    if (strlen(longestWord) > 0) {
        printf("The longest word is: %s\n", longestWord);
        printf("Length: %zu\n", strlen(longestWord));
    } else {
        printf("No valid word found in the string.\n");
    }

    return 0;
}
