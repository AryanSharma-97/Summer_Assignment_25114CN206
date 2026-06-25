// WAP to sort names alphabetically
#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_LENGTH 100

int main() {
    char names[MAX_NAMES][MAX_LENGTH], temp[MAX_LENGTH];
    int n;

    printf("Enter number of names: ");
    scanf("%d", &n);
    getchar(); // clear newline after number input

    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        fgets(names[i], MAX_LENGTH, stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; // remove newline
    }

    // Simple bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("\nSorted names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
