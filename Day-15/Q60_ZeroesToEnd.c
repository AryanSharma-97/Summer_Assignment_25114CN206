// WAP to move zeroes to the end of the array
#include <stdio.h>
void moveZeroesToEnd(int arr[], int size) {
    int count = 0; // Count of non-zero elements
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i]; // Move non-zero element to the front
        }
    }
    while (count < size) {
        arr[count++] = 0; // Fill remaining elements with zero
    }
}
int main() {
    int arr[100], n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    moveZeroesToEnd(arr, n);
    printf("Array after moving zeroes to the end:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}