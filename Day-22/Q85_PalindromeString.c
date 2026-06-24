#include <stdio.h>
int str_length(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
char to_lower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32; // ASCII difference between uppercase and lowercase
    }
    return ch;
}

int main() {
    char str[200];
    int i, j, len;
    int is_palindrome = 1; // Assume true initially

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline if present
    len = str_length(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    // Check palindrome (case-insensitive)
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (to_lower(str[i]) != to_lower(str[j])) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
