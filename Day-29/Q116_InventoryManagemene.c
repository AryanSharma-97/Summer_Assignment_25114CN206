#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    int id;
    char name[50];
    int qty;
    float price;
};

int main() {
    struct item inv[100];
    int n = 0;
    int choice, i, id, found;

    while (1) {
        printf("\n1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter id: ");
                scanf("%d", &inv[n].id);
                printf("Enter name: ");
                scanf("%s", inv[n].name);
                printf("Enter quantity: ");
                scanf("%d", &inv[n].qty);
                printf("Enter price: ");
                scanf("%f", &inv[n].price);
                n++;
                printf("Item added.\n");
                break;

            case 2:
                if (n == 0) {
                    printf("No items.\n");
                } else {
                    for (i = 0; i < n; i++) {
                        printf("%d %s %d %.2f\n", inv[i].id, inv[i].name, inv[i].qty, inv[i].price);
                    }
                }
                break;

            case 3:
                printf("Enter id to search: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (inv[i].id == id) {
                        printf("%d %s %d %.2f\n", inv[i].id, inv[i].name, inv[i].qty, inv[i].price);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Item not found.\n");
                }
                break;

            case 4:
                printf("Enter id to update: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (inv[i].id == id) {
                        printf("Enter new name: ");
                        scanf("%s", inv[i].name);
                        printf("Enter new quantity: ");
                        scanf("%d", &inv[i].qty);
                        printf("Enter new price: ");
                        scanf("%f", &inv[i].price);
                        printf("Item updated.\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Item not found.\n");
                }
                break;

            case 5:
                printf("Enter id to delete: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (inv[i].id == id) {
                        for (int j = i; j < n - 1; j++) {
                            inv[j] = inv[j + 1];
                        }
                        n--;
                        printf("Item deleted.\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Item not found.\n");
                }
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
