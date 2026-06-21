// WAP to find the length of a string
#include <stdio.h>
void stringLength(char str[], int *length) {
    *length = 0; // Initialize length to 0
    while (str[*length] != '\0') { // Loop until the null terminator is reached
        (*length)++; // Increment length for each character
    }
}
int main() {
    char str[100];
    int length;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read a line of input including spaces
    
    stringLength(str, &length); // Call the function to calculate string length
    
    printf("Length of the string: %d\n", length);
    
    return 0;
}