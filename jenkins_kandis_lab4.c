/*
Name: Kandis Jenkins
Lab #4
Date: 10/31/2024
Description: Added new functions, storage classes, and prototype functions to simulate a calculator that will support basic functions and primary testing.
File name: Jenkins_Kandis_lab4.c
*/

#include <stdio.h>
#include <stdlib.h> // For the abs() function

// Function prototypes
int isPrime(int number);
int factorial(int number);
float power(float base, int exponent);
int absoluteValue(int number);
void addition(float num1, float num2);
void subtraction(float num1, float num2);
void multiplication(float num1, float num2);
void division(float num1, float num2);
void modulus(int num1, int num2);

// Global variable example
static int operationCount = 0; // Static global variable

int main() {
    static float num1 = 0, num2 = 0; // Static to retain values if it is needed
    int choice = 0; // Removed register keyword
    int stop = 0;

    do {
        printf("\nCalculator Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Test if Prime\n");
        printf("7. Factorial\n");
        printf("8. Power\n");
        printf("9. Absolute Value\n");
        printf("0. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5) {
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
        }

        if (choice == 1) {
            addition(num1, num2);
        } else if (choice == 2) {
            subtraction(num1, num2);
        } else if (choice == 3) {
            multiplication(num1, num2);
        } else if (choice == 4) {
            division(num1, num2);
        } else if (choice == 5) {
            modulus((int)num1, (int)num2);
        } else if (choice == 6) {
            int num;
            printf("Enter number to check: ");
            scanf("%d", &num);
            if (isPrime(num))
                printf("%d is a prime number.\n", num);
            else {
                printf("Not prime: ");
                for (int i = 2; i * i <= num; i++) {
                    if (num % i == 0) {
                        printf("%d x %d = %d\n", i, num / i, num);
                        break;
                    }
                }
            }
        } else if (choice == 7) {
            int num;
            printf("Enter an integer: ");
            scanf("%d", &num);
            printf("%d! = %d\n", num, factorial(num));
        } else if (choice == 8) {
            int exponent;
            printf("Enter the base number: ");
            scanf("%f", &num1);
            printf("Enter the exponent: ");
            scanf("%d", &exponent);
            printf("%.2f^%d = %.2f\n", num1, exponent, power(num1, exponent));
        } else if (choice == 9) {
            int num;
            printf("Enter a number: ");
            scanf("%d", &num);
            printf("Absolute value of %d = %d\n", num, absoluteValue(num));
        } else if (choice == 0) {
            printf("Goodbye\n");
            stop = 1;
        } else {
            printf("Invalid option.\n");
        }

        operationCount++; // Increment the global counter
    } while (!stop);

    printf("Total operations performed: %d\n", operationCount);

    return 0;
}

// Function definitions
void addition(float num1, float num2) {
    printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
}

void subtraction(float num1, float num2) {
    printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
}

void multiplication(float num1, float num2) {
    printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
}

void division(float num1, float num2) {
    if (num2 != 0)
        printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
    else
        printf("Error: Division by zero.\n");
}

void modulus(int num1, int num2) {
    if (num2 != 0)
        printf("%d %% %d = %d\n", num1, num2, num1 % num2);
    else
        printf("Error: Division by zero.\n");
}

int isPrime(int number) {
    if (number <= 1) return 0;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return 0;
    }
    return 1;
}

int factorial(int number) {
    if (number == 0) return 1;
    return number * factorial(number - 1);
}

float power(float base, int exponent) {
    float result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int absoluteValue(int number) {
    return abs(number);
}