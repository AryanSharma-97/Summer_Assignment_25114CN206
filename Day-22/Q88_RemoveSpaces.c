// WAP to remove spaces ffrom a string
#include <stdio.h>
int main() {
    char str[100], result[100];
    int i, j = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove spaces
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            result[j++] = str[i];
        }
    }
    result[j] = '\0'; // Null-terminate the result string

    printf("String after removing spaces: \"%s\"\n", result);
    return 0;
}