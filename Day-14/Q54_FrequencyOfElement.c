// WAP for frequency of element in an array
#include <stdio.h>
int linearSearch(int arr[], int size, int key) {
    int f=0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            f++; 
        }
    }
    return f; // Return frequency of the element
}
int main() {
    int arr[100], n, key;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int result = linearSearch(arr, n, key);
    printf("Frequency of the element %d in the array: %d\n", key, result);
    return 0;
}