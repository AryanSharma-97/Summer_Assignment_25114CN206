// WAP to find largest and smallest elements in an array
#include <stdio.h>
int main() {
    int arr[100], n, largest, smallest;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    largest = smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    printf("Largest element in the array: %d\n", largest);
    printf("Smallest element in the array: %d\n", smallest);
    return 0;
}