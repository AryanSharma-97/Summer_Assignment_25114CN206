// WAP to find the maximum frequency element in an array
#include <stdio.h>
int findMaxFrequencyElement(int arr[], int size) {
    int maxCount = 0, maxElement = arr[0];
    for (int i = 0; i < size; i++) {
        int count = 1; // Count the frequency of arr[i]
        for (int j = i + 1; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxElement = arr[i];
        }
    }
    return maxElement;
}
int main() {
    int arr[100], n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int maxFreqElement = findMaxFrequencyElement(arr, n);
    printf("The maximum frequency element is: %d\n", maxFreqElement);
    return 0;
}