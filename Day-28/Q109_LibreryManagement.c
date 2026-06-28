// WAP tp create a librery management system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100

// Structure to store book details
typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int available;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void deleteBook();
int getIntInput(const char *prompt);

int main() {
    int choice;

    while (1) {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Delete Book by ID\n");
        printf("5. Exit\n");
        choice = getIntInput("Enter your choice: ");

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: printf("Exiting program. Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to safely get integer input
int getIntInput(const char *prompt) {
    int value;
    char ch;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            while ((ch = getchar()) != '\n' && ch != EOF); // clear buffer
            return value;
        } else {
            printf("Invalid input. Please enter a number.\n");
            while ((ch = getchar()) != '\n' && ch != EOF); // clear buffer
        }
    }
}

// Add a new book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book newBook;
    newBook.id = getIntInput("Enter Book ID: ");

    printf("Enter Book Title: ");
    fgets(newBook.title, TITLE_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // remove newline

    printf("Enter Author Name: ");
    fgets(newBook.author, AUTHOR_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    newBook.available = 1; // default available
    library[bookCount++] = newBook;

    printf("Book added successfully!\n");
}

// Display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n%-5s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Status");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-5d %-30s %-20s %-10s\n",
               library[i].id,
               library[i].title,
               library[i].author,
               library[i].available ? "Available" : "Issued");
    }
}

// Search for a book by ID
void searchBook() {
    if (bookCount == 0) {
        printf("No books to search.\n");
        return;
    }

    int id = getIntInput("Enter Book ID to search: ");
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            printf("Book Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n",
                   library[i].id,
                   library[i].title,
                   library[i].author,
                   library[i].available ? "Available" : "Issued");
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

// Delete a book by ID
void deleteBook() {
    if (bookCount == 0) {
        printf("No books to delete.\n");
        return;
    }

    int id = getIntInput("Enter Book ID to delete: ");
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            printf("Book deleted successfully.\n");
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}
