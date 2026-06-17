// WAP to remove duplicate elementss from an array
#include <stdio.h>
#include<stdlib.h>
int removeDuplicates(int arr[], int size) {
    if (size == 0 || size == 1) {
        return size;
    }
    int temp[size];
    int j = 0; // Index for temp array
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            temp[j++] = arr[i]; // Store unique element
        }
    }
    temp[j++] = arr[size - 1]; // Store the last element
    for (int i = 0; i < j; i++) {
        arr[i] = temp[i]; // Copy unique elements back to original array
    }
    return j;
}
int main() {
    int arr[100], n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements (sorted order):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int newSize = removeDuplicates(arr, n);
    printf("Array after removing duplicates:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}