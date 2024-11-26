/*
Name: Kandis Jenkins
Lab #3
Date: 10/15/2024
Description: To simulate a calculator that will support 5 basic functions and primary testing.
File name: Jenkins_Kandis_lab3.c
*/

#include <stdio.h>
#include <stdlib.h> // The Libary for the abs function. 

// To Declare Prime Function and Porotypes functions
int isPrime(int number);
int factorial (int number);
float power (float base, int exponent);
int absolute Value (int number);
void addition (float num1, float num2);
void subtraction (float num1, float num2);
void multiplication (float num1, float num2);
void division (float num1, float num2);
void modulus (int num1, int num2);

// Global Varible
static int globalcounter= 0; //static global varible

int main() {
	static float num1 = 0, num2 =0;
}


int main() {
    float num1 = 0, num2 = 0, temp = 0;
    int choice = 0;
    int stop = 0;

    do {
        printf("\nCalculator Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Test if Prime\n");
        printf("7. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);

        if (choice == 6) {
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
        } else if (choice >= 1 && choice <= 5) {
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);

            if (choice == 1) {
                temp = num1 + num2;
                printf("%.2f + %.2f = %.2f\n", num1, num2, temp);
            } else if (choice == 2) {
                temp = num1 - num2;
                printf("%.2f - %.2f = %.2f\n", num1, num2, temp);
            } else if (choice == 3) {
                temp = num1 * num2;
                printf("%.2f * %.2f = %.2f\n", num1, num2, temp);
            } else if (choice == 4) {
                temp = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, temp);
            } else if (choice == 5) {
                temp = (int)num1 % (int)num2;
                printf("%d %% %d = %d\n", (int)num1, (int)num2, (int)temp);
            }
        } else if (choice == 7) {
            printf("Goodbye\n");
            stop = 1;
        } else {
            printf("Invalid option.\n");
        }
    } while (!stop);

    return 0;
}

int isPrime(int number) {
    if (number <= 1) return 0;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return 0;
    }
    return 1;
}