// WAP to find the missing number in an array of size n containing numbers from 1 to n
#include <stdio.h>
int findMissingNumber(int arr[], int size) {
    int total = (size + 1) * (size + 2) / 2; // Sum of first n natural numbers
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i]; // Sum of elements in the array
    }
    return total - sum; // Missing number is the difference
}
int main() {
    int arr[100], n;
    printf("Enter the number of elements in the array (n-1): ");
    scanf("%d", &n);
    printf("Enter %d elements (from 1 to %d with one missing):\n", n, n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int missingNumber = findMissingNumber(arr, n);
    printf("The missing number is: %d\n", missingNumber);
    return 0;
}