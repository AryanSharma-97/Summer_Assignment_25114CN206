// WAP to count vowels and consonants in a string
#include <stdio.h>
void countVowelsAndConsonants(char str[], int *vowelCount, int *consonantCount) {
    *vowelCount = 0;
    *consonantCount = 0;
    for (int i = 0; str[i] != '\0'; i++) { 
        char ch = str[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) { 
            // Check for vowels
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
                ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                (*vowelCount)++; // Increment vowel count
            } else {
                (*consonantCount)++; // Increment consonant count
            }
        }
    }
}
int main() {
    char str[100];
    int vowelCount, consonantCount;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read a line of input including spaces
    
    countVowelsAndConsonants(str, &vowelCount, &consonantCount); // Call the function to count vowels and consonants
    
    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);
    
    return 0;
}