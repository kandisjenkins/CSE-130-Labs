/*
Name: Kandis Jenkins
Lab #5
Date: 11/15/2024
Description:  C program that generates a personalized story based on the user's name, age, passion, and a random selection of words and scenarios.
File name: Jenkins_Kandis_lab5.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LEN 100

int main() {
    char name[MAX_LEN]; // Array to store name
    char age[MAX_LEN]; // Array to store age
    char passion[MAX_LEN]; // Array to store passion
    int choice; // Variable to store choice

    // Get name
    printf("What is your name: ");
    gets(name);

    // Get age
    printf("\nHow old are you: ");
    gets(age);

    // Get passion
    printf("\nWhat are you passionate about: ");
    gets(passion);

    // Arrays of random words for the story
    char *places[4] = {"the beach", "the city", "the village", "the mountain"};
    char *activities[4] = {"reading", "painting", "playing music", "cooking"};
    char *companions[4] = {"a dog", "a cat", "an old man", "a child"};
    char *endings[4] = {"they found out they were good at it.", "they made a new friend.", "they found something cool.", "they learned something new."};

    srand(time(0)); 
    int randChoice = rand() % 4; // Pick random number between 0 and 3

    // Get choice
    printf("\nPick a number between 1 and 3: ");
    scanf("%d", &choice);

    // One paragraph story
    printf("\n%s is %s years old and loves %s. ", name, age, passion);
    if (choice == 1) {
        printf("They worked on a project all day and did a good job. ");
    } else if (choice == 2) {
        printf("They went to a workshop and learned a lot. ");
    } else {
        printf("They helped people in the community. ");
    }
    printf("In their free time, they like to go to %s and do %s with %s. ", places[randChoice], activities[randChoice], companions[randChoice]);
    printf("They were born in %s but live somewhere else now. ", places[randChoice]);
    printf("They had a project for school and didn't know what to write, so they wrote about the up coming election. But then %s\n", endings[randChoice]);

    return 0;
}