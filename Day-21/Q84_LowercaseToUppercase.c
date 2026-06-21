// WAOP to convert lowercase to uppercase using C programming language.
#include <stdio.h>
void convertToUppercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') { // Check if the character is lowercase
            str[i] = str[i] - ('a' - 'A'); // Convert to uppercase
        }
    }
}
int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read a line of input including spaces
    
    convertToUppercase(str); // Call the function to convert to uppercase
    
    printf("Uppercase string: %s\n", str);
    
    return 0;
}