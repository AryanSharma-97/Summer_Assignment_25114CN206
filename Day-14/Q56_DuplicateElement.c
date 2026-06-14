// WAP to find duplicate elements in array
#include <stdio.h>
int main() {
    int arr[100], n, i, j, isDuplicate;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Duplicate elements in the array are:\n");
    for (i = 0; i < n; i++) {
        isDuplicate = 0;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            for (j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    printf("%d\n", arr[i]);
                    break;
                }
            }
        }
    }
    return 0;
}