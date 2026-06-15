// WAP to rotate an array left
#include <stdio.h>
void rotateLeft(int arr[], int size) {
    int temp = arr[0]; // Store the first element
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    arr[size - 1] = temp; // Place the first element at the end
}
int main() {
    int arr[100], n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    rotateLeft(arr, n);
    printf("Array after left rotation:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}