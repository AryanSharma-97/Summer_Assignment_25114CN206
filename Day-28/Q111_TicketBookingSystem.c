#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 50
#define NAME_LEN 50

// Structure to store booking details
typedef struct {
    int seatNumber;
    char name[NAME_LEN];
    int booked; // 0 = available, 1 = booked
} Seat;

// Function prototypes
void initializeSeats(Seat seats[], int totalSeats);
void displaySeats(Seat seats[], int totalSeats);
void bookSeat(Seat seats[], int totalSeats);
void cancelBooking(Seat seats[], int totalSeats);

int main() {
    Seat seats[MAX_SEATS];
    int totalSeats = 10; // You can change this as needed
    int choice;

    initializeSeats(seats, totalSeats);

    while (1) {
        printf("\n===== Ticket Booking System =====\n");
        printf("1. View Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                displaySeats(seats, totalSeats);
                break;
            case 2:
                bookSeat(seats, totalSeats);
                break;
            case 3:
                cancelBooking(seats, totalSeats);
                break;
            case 4:
                printf("Thank you for using the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Initialize all seats as available
void initializeSeats(Seat seats[], int totalSeats) {
    for (int i = 0; i < totalSeats; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].booked = 0;
        strcpy(seats[i].name, "");
    }
}

// Display seat status
void displaySeats(Seat seats[], int totalSeats) {
    printf("\nSeat Status:\n");
    for (int i = 0; i < totalSeats; i++) {
        printf("Seat %2d: %s\n", seats[i].seatNumber,
               seats[i].booked ? seats[i].name : "Available");
    }
}

// Book a seat
void bookSeat(Seat seats[], int totalSeats) {
    int seatNum;
    char name[NAME_LEN];

    printf("Enter seat number to book (1-%d): ", totalSeats);
    if (scanf("%d", &seatNum) != 1 || seatNum < 1 || seatNum > totalSeats) {
        printf("Invalid seat number!\n");
        while (getchar() != '\n');
        return;
    }

    if (seats[seatNum - 1].booked) {
        printf("Seat %d is already booked by %s.\n", seatNum, seats[seatNum - 1].name);
        return;
    }

    printf("Enter your name: ");
    while (getchar() != '\n'); // clear buffer
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove newline

    seats[seatNum - 1].booked = 1;
    strncpy(seats[seatNum - 1].name, name, NAME_LEN - 1);
    seats[seatNum - 1].name[NAME_LEN - 1] = '\0';

    printf("Seat %d successfully booked for %s.\n", seatNum, name);
}

// Cancel a booking
void cancelBooking(Seat seats[], int totalSeats) {
    int seatNum;

    printf("Enter seat number to cancel (1-%d): ", totalSeats);
    if (scanf("%d", &seatNum) != 1 || seatNum < 1 || seatNum > totalSeats) {
        printf("Invalid seat number!\n");
        while (getchar() != '\n');
        return;
    }

    if (!seats[seatNum - 1].booked) {
        printf("Seat %d is not booked.\n", seatNum);
        return;
    }

    seats[seatNum - 1].booked = 0;
    strcpy(seats[seatNum - 1].name, "");
    printf("Booking for seat %d has been cancelled.\n", seatNum);
}
