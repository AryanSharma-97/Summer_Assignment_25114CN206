#include <stdio.h>
#include <stdlib.h>

struct Book {
    int id;
    char title[100];
    char author[100];
};

struct Book library[100];
int count = 0;

void addBook() {
    if (count >= 100) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &library[count].id);

    printf("Enter Book Title: ");
    scanf("%s", library[count].title);

    printf("Enter Author Name: ");
    scanf("%s", library[count].author);

    count++;
    printf("Book added successfully!\n");
}

void listBooks() {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n--- Book List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Title: %s | Author: %s\n",
               library[i].id, library[i].title, library[i].author);
    }
}

void removeBook() {
    if (count == 0) {
        printf("No books to remove.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Book ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                library[j] = library[j + 1];
            }
            count--;
            printf("Book removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Mini Library =====\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Remove Book\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: listBooks(); break;
            case 3: removeBook(); break;
            case 4: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
