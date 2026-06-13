// WAP to even and odd sum of array elements
#include <stdio.h>
int main() {
    int arr[100], n, evenSum = 0, oddSum = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) {
            evenSum += arr[i];
        } else {
            oddSum += arr[i];
        }
    }
    printf("Sum of even elements in the array: %d\n", evenSum);
    printf("Sum of odd elements in the array: %d\n", oddSum);
    return 0;
}