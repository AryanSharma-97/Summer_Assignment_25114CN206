// WAP to to find sum and average of array elements
#include <stdio.h>
int main() {
    int arr[100], n, sum = 0;
    float avg;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    avg = (float)sum / n;
    printf("Sum of array elements: %d\n", sum);
    printf("Average of array elements: %.2f\n", avg);
    return 0;
}