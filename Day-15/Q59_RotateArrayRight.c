// WAP to to rotate an array right
#include <stdio.h>
void rotateRight(int arr[], int size) {
    int temp = arr[size - 1]; // Store the last element
    for (int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1]; // Shift elements to the right
    }
    arr[0] = temp; // Place the last element at the beginning
}
int main() {
    int arr[100], n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    rotateRight(arr, n);
    printf("Array after right rotation:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}