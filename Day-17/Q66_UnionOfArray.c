// WAP for union of two arrays
#include <stdio.h>
void unionArrays(int arr1[], int n1, int arr2[], int n2, int unionArr[], int *unionSize) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            unionArr[k++] = arr1[i++];
        } else if (arr1[i] > arr2[j]) {
            unionArr[k++] = arr2[j++];
        } else {
            unionArr[k++] = arr1[i++];
            j++;
        }
    }
    while (i < n1) {
        unionArr[k++] = arr1[i++];
    }
    while (j < n2) {
        unionArr[k++] = arr2[j++];
    }
    *unionSize = k;
}
int main() {
    int arr1[100], arr2[100], unionArr[200];
    int n1, n2, unionSize;
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
    unionArrays(arr1, n1, arr2, n2, unionArr, &unionSize);
    printf("Union of the two arrays:\n");
    for (int i = 0; i < unionSize; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");
    return 0;
}