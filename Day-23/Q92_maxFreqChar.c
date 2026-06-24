// WAP to Find maximum freq Charecter
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000  // Maximum input string length

int main() {
    char str[MAX_LEN];
    int freq[256] = {0}; // Frequency array for all ASCII characters
    int i, maxFreq = 0;
    char maxChar = '\0';

    // Input string
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Handle empty string
    if (strlen(str) == 0) {
        printf("Empty string entered.\n");
        return 0;
    }

    // Count frequency of each character
    for (i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];
        freq[ch]++;
        if (freq[ch] > maxFreq) {
            maxFreq = freq[ch];
            maxChar = ch;
        }
    }

    // Output result
    printf("Maximum occurring character: '%c'\n", maxChar);
    printf("Frequency: %d\n", maxFreq);

    return 0;
}
