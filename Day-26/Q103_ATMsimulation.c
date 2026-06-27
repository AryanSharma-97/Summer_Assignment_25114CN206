#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void checkBalance(float balance);
float deposit(float balance);
float withdraw(float balance);

int main() {
    int pin, enteredPin, choice;
    float balance = 1000.0f; // Initial balance
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;

    pin = 1234; // Predefined PIN for simulation

    printf("===== Welcome to ATM Simulator =====\n");

    // PIN verification with limited attempts
    while (attempts < MAX_ATTEMPTS) {
        printf("Enter your 4-digit PIN: ");
        if (scanf("%d", &enteredPin) != 1) {
            printf("Invalid input. Please enter numbers only.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (enteredPin == pin) {
            printf("PIN verified successfully!\n");
            break;
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts left: %d\n", MAX_ATTEMPTS - attempts);
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Too many incorrect attempts. Card blocked.\n");
        return 0;
    }

    // ATM menu loop
    do {
        printf("\n===== ATM Menu =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = deposit(balance);
                break;
            case 3:
                balance = withdraw(balance);
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to check balance
void checkBalance(float balance) {
    printf("Your current balance is: ₹%.2f\n", balance);
}

// Function to deposit money
float deposit(float balance) {
    float amount;
    printf("Enter amount to deposit: ₹");
    if (scanf("%f", &amount) != 1 || amount <= 0) {
        printf("Invalid amount. Deposit cancelled.\n");
        while (getchar() != '\n'); // Clear buffer
        return balance;
    }
    balance += amount;
    printf("₹%.2f deposited successfully.\n", amount);
    return balance;
}

// Function to withdraw money
float withdraw(float balance) {
    float amount;
    printf("Enter amount to withdraw: ₹");
    if (scanf("%f", &amount) != 1 || amount <= 0) {
        printf("Invalid amount. Withdrawal cancelled.\n");
        while (getchar() != '\n'); // Clear buffer
        return balance;
    }
    if (amount > balance) {
        printf("Insufficient balance. Withdrawal cancelled.\n");
    } else {
        balance -= amount;
        printf("₹%.2f withdrawn successfully.\n", amount);
    }
    return balance;
}
