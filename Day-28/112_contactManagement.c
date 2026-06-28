#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

struct Contact contacts[MAX];
int count = 0;

void addContact() {
    if (count >= MAX) {
        printf("Contact list is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]", contacts[count].name);
    printf("Enter phone: ");
    scanf(" %[^\n]", contacts[count].phone);
    printf("Enter email: ");
    scanf(" %[^\n]", contacts[count].email);
    count++;
    printf("Contact added!\n");
}

void viewContacts() {
    if (count == 0) {
        printf("No contacts to show.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\nContact %d:\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
    }
}

void searchContact() {
    char name[50];
    int found = 0;
    printf("Enter name to search: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found Contact:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void editContact() {
    char name[50];
    int found = 0;
    printf("Enter name to edit: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Enter new name: ");
            scanf(" %[^\n]", contacts[i].name);
            printf("Enter new phone: ");
            scanf(" %[^\n]", contacts[i].phone);
            printf("Enter new email: ");
            scanf(" %[^\n]", contacts[i].email);
            printf("Contact updated!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact() {
    char name[50];
    int found = 0;
    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            printf("Contact deleted!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Contact Management ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) addContact();
        else if (choice == 2) viewContacts();
        else if (choice == 3) searchContact();
        else if (choice == 4) editContact();
        else if (choice == 5) deleteContact();
        else if (choice == 6) break;
        else printf("Invalid choice!\n");
    }
    return 0;
}
