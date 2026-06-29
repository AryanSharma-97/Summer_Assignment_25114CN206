#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function prototypes
void displayArray(int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void searchElement(int arr[], int size);
void sortArray(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0, choice;
    printf("Enter number of elements (max %d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 0 || size > MAX_SIZE) {
        printf("Invalid size!\n");
        return 1;
    }
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input! Please enter integers only.\n");
            return 1;
        }
    }

    while (1) {
        // Menu
        printf("\n===== Menu Driven Array Operations =====\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Sort Array\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 6.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        switch (choice) {
            case 1: displayArray(arr, size); break;
            case 2: insertElement(arr, &size); break;
            case 3: deleteElement(arr, &size); break;
            case 4: searchElement(arr, size); break;
            case 5: sortArray(arr, size); break;
            case 6: 
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}
void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertElement(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    int pos, value;
    printf("Enter position to insert (0 to %d): ", *size);
    if (scanf("%d", &pos) != 1 || pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }
    printf("Enter value to insert: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid value!\n");
        return;
    }
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
    printf("Element inserted successfully.\n");
}
void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("Array is empty! Cannot delete.\n");
        return;
    }
    int pos;
    printf("Enter position to delete (0 to %d): ", *size - 1);
    if (scanf("%d", &pos) != 1 || pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element deleted successfully.\n");
}
void searchElement(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    int value, found = 0;
    printf("Enter value to search: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid value!\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("Element found at position %d.\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element not found in array.\n");
    }
}
void sortArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}