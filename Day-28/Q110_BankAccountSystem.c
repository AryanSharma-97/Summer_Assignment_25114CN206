#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void displayMenu();
int accountExists(int accNo);
void createAccount();
void viewAccount();
void depositMoney();
void withdrawMoney();
void deleteAccount();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }
        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAccount(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: deleteAccount(); break;
            case 0: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);
    return 0;
}

void displayMenu() {
    printf("\n===== BANK ACCOUNT SYSTEM (In-Memory) =====\n");
    printf("1. Create Account\n");
    printf("2. View Account\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Delete Account\n");
    printf("0. Exit\n");
    printf("===========================================\n");
}

int accountExists(int accNo) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNo) {
            return i; // return index
        }
    }
    return -1;
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Limit reached.\n");
        return;
    }
    Account acc;
    printf("Enter account number: ");
    scanf("%d", &acc.accountNumber);
    if (accountExists(acc.accountNumber) != -1) {
        printf("Account number already exists!\n");
        return;
    }
    printf("Enter name: ");
    getchar(); // clear newline
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0';
    printf("Enter initial deposit: ");
    scanf("%f", &acc.balance);

    accounts[accountCount++] = acc;
    printf("Account created successfully!\n");
}

void viewAccount() {
    int accNo;
    printf("Enter account number: ");
    scanf("%d", &accNo);
    int idx = accountExists(accNo);
    if (idx == -1) {
        printf("Account not found!\n");
        return;
    }
    printf("\nAccount Number: %d\nName: %s\nBalance: %.2f\n",
           accounts[idx].accountNumber, accounts[idx].name, accounts[idx].balance);
}

void depositMoney() {
    int accNo;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNo);
    int idx = accountExists(accNo);
    if (idx == -1) {
        printf("Account not found!\n");
        return;
    }
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }
    accounts[idx].balance += amount;
    printf("Deposit successful! New balance: %.2f\n", accounts[idx].balance);
}

void withdrawMoney() {
    int accNo;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNo);
    int idx = accountExists(accNo);
    if (idx == -1) {
        printf("Account not found!\n");
        return;
    }
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0 || amount > accounts[idx].balance) {
        printf("Invalid amount or insufficient balance!\n");
        return;
    }
    accounts[idx].balance -= amount;
    printf("Withdrawal successful! New balance: %.2f\n", accounts[idx].balance);
}

void deleteAccount() {
    int accNo;
    printf("Enter account number to delete: ");
    scanf("%d", &accNo);
    int idx = accountExists(accNo);
    if (idx == -1) {
        printf("Account not found!\n");
        return;
    }
    // Shift accounts left to overwrite deleted account
    for (int i = idx; i < accountCount - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    accountCount--;
    printf("Account deleted successfully!\n");
}
