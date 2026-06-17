// WAP to Find common elements in two arrays
#include <stdio.h>
void findCommonElements(int arr1[], int n1, int arr2[], int n2, int commonArr[], int *commonSize) {
    int k = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                commonArr[k++] = arr1[i];
                break;
            }
        }
    }
    *commonSize = k;
}
int main() {
    int arr1[100], arr2[100], commonArr[100];
    int n1, n2, commonSize;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    printf("Enter %d elements for the first array:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    printf("Enter %d elements for the second array:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    findCommonElements(arr1, n1, arr2, n2, commonArr, &commonSize);
    printf("Common elements in the two arrays:\n");
    for (int i = 0; i < commonSize; i++) {
        printf("%d ", commonArr[i]);
    }
    printf("\n");
    return 0;
}