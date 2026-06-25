#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], common[100];
    int index = 0;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline

    // Find common characters
    for (int i = 0; str1[i] != '\0'; i++) {
        for (int j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                // Check if already added
                int alreadyAdded = 0;
                for (int k = 0; k < index; k++) {
                    if (common[k] == str1[i]) {
                        alreadyAdded = 1;
                        break;
                    }
                }
                if (!alreadyAdded) {
                    common[index++] = str1[i];
                }
                break; // Move to next char in str1
            }
        }
    }
    common[index] = '\0';

    if (index > 0)
        printf("Common characters: %s\n", common);
    else
        printf("No common characters found.\n");

    return 0;
}
