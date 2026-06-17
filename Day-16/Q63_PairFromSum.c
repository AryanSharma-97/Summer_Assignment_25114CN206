// WAP to find pair of number from given sum
#include <stdio.h>
int PairWithSum(int arr[], int size, int targetSum) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == targetSum) {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                return 1; // Pair found
            }
        }
    }
    return 0; // No pair found
}
int main() {
    int arr[100], n, targetSum;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    if (!PairWithSum(arr, n, targetSum)) {
        printf("No pair found with the given sum.\n");
    }
    return 0;
}