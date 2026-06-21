// WAP to reverse a string
#include <stdio.h>
void reverseString(char str[]) {
    int length = 0;
    while (str[length] != '\0') { // Calculate the length of the string
        length++;
    }
    
    for (int i = 0; i < length / 2; i++) { // Swap characters from both ends
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}
int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read a line of input including spaces
    
    reverseString(str); // Call the function to reverse the string
    
    printf("Reversed string: %s\n", str);
    
    return 0;
}