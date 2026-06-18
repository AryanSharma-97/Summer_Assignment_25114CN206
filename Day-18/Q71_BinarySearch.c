// WAP to implement binary search
#include<stdio.h>
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x) {
            return m; // Element found at index m
        }
        if (arr[m] < x) {
            l = m + 1; // Search in the right half
        } else {
            r = m - 1; // Search in the left half
        }
    }
    return -1; // Element not found
}
int main() {
    int n, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &x);
    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}