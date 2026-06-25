// WAP to merge two sorted arrey
#include <stdio.h>

int main() {
    int n1, n2;

    // Input sizes
    printf("Enter size of first sorted array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d elements (ascending order): ", n1);
    for (int i = 0; i < n1; i++) scanf("%d", &arr1[i]);

    printf("Enter size of second sorted array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d elements (ascending order): ", n2);
    for (int i = 0; i < n2; i++) scanf("%d", &arr2[i]);

    int merged[n1 + n2];
    int i = 0, j = 0, k = 0;

    // Merge process
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    // Copy remaining elements
    while (i < n1) merged[k++] = arr1[i++];
    while (j < n2) merged[k++] = arr2[j++];

    // Output merged array
    printf("Merged sorted array: ");
    for (int x = 0; x < n1 + n2; x++)
        printf("%d ", merged[x]);
    printf("\n");

    return 0;
}
