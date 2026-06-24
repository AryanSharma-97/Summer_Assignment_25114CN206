// WAP to check if the string is anagram
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if two sentences are anagrams
int areAnagrams(char str1[], char str2[]) {
    int count[256] = {0};

    // Count characters from str1 (ignoring spaces/punctuation)
    for (int i = 0; str1[i]; i++) {
        if (isalpha((unsigned char)str1[i])) // only letters
            count[tolower((unsigned char)str1[i])]++;
    }

    // Subtract characters from str2
    for (int i = 0; str2[i]; i++) {
        if (isalpha((unsigned char)str2[i]))
            count[tolower((unsigned char)str2[i])]--;
    }

    // If all counts are zero, they are anagrams
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0)
            return 0;
    }
    return 1;
}

int main() {
    char str1[200], str2[200];

    printf("Enter first sentence: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second sentence: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove newline characters from fgets
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    if (areAnagrams(str1, str2))
        printf("Anagram\n");
    else
        printf("Not an Anagram\n");

    return 0;
}
