#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 200

void displayString(char str[]);
void concatenateStrings(char str[]);
void stringLength(char str[]);
void copyString(char str[]);
void compareStrings();
void reverseString(char str[]);

int main() {
    char str[MAX_LEN];
    int choice;

    printf("Enter initial string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading string.\n");
        return 1;
    }
    str[strcspn(str, "\n")] = '\0';

    while (1) {
        printf("\n===== Menu Driven String Operations =====\n");
        printf("1. Display String\n");
        printf("2. Concatenate Another String\n");
        printf("3. Find String Length\n");
        printf("4. Copy String\n");
        printf("5. Compare with Another String\n");
        printf("6. Reverse String\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 7.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1: displayString(str); break;
            case 2: concatenateStrings(str); break;
            case 3: stringLength(str); break;
            case 4: copyString(str); break;
            case 5: compareStrings(); break;
            case 6: reverseString(str); break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 7.\n");
        }
    }
    return 0;
}

void displayString(char str[]) {
    printf("Current String: \"%s\"\n", str);
}

void concatenateStrings(char str[]) {
    char temp[MAX_LEN];
    printf("Enter string to concatenate: ");
    if (fgets(temp, sizeof(temp), stdin) == NULL) {
        printf("Error reading string.\n");
        return;
    }
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(str) + strlen(temp) >= MAX_LEN) {
        printf("Error: Resulting string would exceed maximum length.\n");
        return;
    }
    strcat(str, temp);
    printf("Strings concatenated successfully.\n");
}

void stringLength(char str[]) {
    printf("Length of string: %zu\n", strlen(str));
}

void copyString(char str[]) {
    char dest[MAX_LEN];
    strcpy(dest, str);
    printf("Copied String: \"%s\"\n", dest);
}

void compareStrings() {
    char str1[MAX_LEN], str2[MAX_LEN];
    printf("Enter first string: ");
    if (fgets(str1, sizeof(str1), stdin) == NULL) return;
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    if (fgets(str2, sizeof(str2), stdin) == NULL) return;
    str2[strcspn(str2, "\n")] = '\0';

    int cmp = strcmp(str1, str2);
    if (cmp == 0)
        printf("Strings are equal.\n");
    else if (cmp > 0)
        printf("First string is greater.\n");
    else
        printf("Second string is greater.\n");
}

void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("String reversed successfully.\n");
}
