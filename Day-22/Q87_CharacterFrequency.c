// WAP to count character frequency in a string
#include <stdio.h>  
int main() {  
    char str[100];  
    int freq[256] = {0}; // Array to store frequency of each character
    int i;  

    printf("Enter a string: ");  
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Count frequency of each character
    for (i = 0; str[i] != '\0'; i++) {  
        freq[(unsigned char)str[i]]++;  
    }  

    printf("Character frequencies:\n");  
    for (i = 0; i < 256; i++) {  
        if (freq[i] > 0) {  
            printf("'%c' : %d\n", i, freq[i]);  
        }  
    }  

    return 0;  
}