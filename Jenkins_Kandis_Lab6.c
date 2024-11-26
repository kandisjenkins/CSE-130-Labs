/*
Name: Kandis Jenkins
Lab #6
Date: 11/10/2024
Description:  phone book program in C. You can add, delete, and show friends' contact info using an array of structures.
File name: Jenkins_Kandis_lab6.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum length for names and phone numbers
#define NAME_LEN 30
#define PHONE_NUM_LEN 15

// Structure to hold contact information
typedef struct {
    char firstName[NAME_LEN]; // First name of the friend
    char lastName[NAME_LEN];  // Last name of the friend
    char phoneNumber[PHONE_NUM_LEN]; // Phone number of the friend
} Friend;

// Function prototypes
void addFriend(Friend **phoneBook, int *count, int *capacity); // Function to add a friend
void deleteFriend(Friend **phoneBook, int *count); // Function to delete a friend
void showPhoneBook(Friend **phoneBook, int count); // Function to show all friends

int main() {
    int capacity = 10; // Initial capacity of the phone book
    Friend **phoneBook = malloc(capacity * sizeof(Friend*)); // Allocate memory for the phone book
    for (int i = 0; i < capacity; i++) {
        phoneBook[i] = NULL; // Initialize all pointers to NULL
    }
    int count = 0; // Number of friends in the phone book
    int choice; // User's menu choice

    while (1) { // Infinite loop for the menu
        // Print the menu
        printf("Phone Book Application\n");
        printf("1) Add friend\n");
        printf("2) Delete friend\n");
        printf("3) Show phone book\n");
        printf("4) Exit\n");
        printf("Please select what you would like to do: ");
        scanf("%d", &choice); // Get the user's choice

        // Perform the action based on the user's choice
        if (choice == 1) {
            addFriend(phoneBook, &count, &capacity); // Add a friend
        } else if (choice == 2) {
            deleteFriend(phoneBook, &count); // Delete a friend
        } else if (choice == 3) {
            showPhoneBook(phoneBook, count); // Show all friends
        } else if (choice == 4) {
            break; // Exit the loop
        } else {
            printf("Try again.\n"); // Invalid choice
        }
    }

    // Free the allocated memory
    for (int i = 0; i < capacity; i++) {
        if (phoneBook[i] != NULL) {
            free(phoneBook[i]);
        }
    }
    free(phoneBook);
    return 0; // End of the program
}

// Function to add a friend
void addFriend(Friend **phoneBook, int *count, int *capacity) {
    // Check if the phone book is full
    if (*count >= *capacity) {
        *capacity *= 2; // Double the capacity
        phoneBook = realloc(phoneBook, *capacity * sizeof(Friend*)); // Reallocate memory
        for (int i = *count; i < *capacity; i++) {
            phoneBook[i] = NULL; // Initialize new pointers to NULL
        }
    }

    // Find the first NULL spot in the array
    int index = -1;
    for (int i = 0; i < *capacity; i++) {
        if (phoneBook[i] == NULL) {
            index = i;
            break;
        }
    }

    // Allocate memory for the new friend
    phoneBook[index] = malloc(sizeof(Friend));

    // Get the friend's information from the user
    printf("First name: ");
    scanf("%s", phoneBook[index]->firstName);
    printf("Last name: ");
    scanf("%s", phoneBook[index]->lastName);
    printf("Phone number: ");
    scanf("%s", phoneBook[index]->phoneNumber);

    (*count)++; // Increase the count of friends
    printf("Added to the phone book\n"); // Confirm addition
}

// Function to delete a friend
void deleteFriend(Friend **phoneBook, int *count) {
    char firstName[NAME_LEN], lastName[NAME_LEN]; // Variables to hold the friend's name
    // Get the friend's name from the user
    printf("First name: ");
    scanf("%s", firstName);
    printf("Last name: ");
    scanf("%s", lastName);

    // Find the friend in the phone book
    for (int i = 0; i < *count; i++) {
        if (phoneBook[i] != NULL && strcmp(phoneBook[i]->firstName, firstName) == 0 && strcmp(phoneBook[i]->lastName, lastName) == 0) {
            free(phoneBook[i]); // Free memory
            phoneBook[i] = NULL; // Pointer to NULL
            (*count)--; // Decrease the count of friends
            printf("Removed.\n"); // Confirm removal
            return;
        }
    }

    printf("Name not found.\n"); // Friend not found
}

// Function to show all friends
void showPhoneBook(Friend **phoneBook, int count) {
    printf("Phone Book Entries:\n"); // Print header
    // Loop through the phone book and print each friend
    for (int i = 0; i < count; i++) {
        if (phoneBook[i] != NULL) {
            printf("%s %s %s\n", phoneBook[i]->firstName, phoneBook[i]->lastName, phoneBook[i]->phoneNumber);
        }
    }
}