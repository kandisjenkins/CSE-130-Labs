/*
Name: Kandis Jenkins
Lab #2
Date: 09/04/2024
Description: Currency table for 6 different currencies
File name: Jenkins_Kandis_lab2.c
*/


#include <stdio.h>

float convert(float curr1, float curr2, float amount) {
    // Multiply exchange rate by amount of currency
    return (curr1 / curr2) * amount; // After the conversion
}

int main() {
    // Currency exchange in USD
    float USD = 1;
    int num_currencies = 6;
    const char *currencies[6] = {"USD", "NZD", "INR", "PKR", "RUB", "MXN"}; // New Zealand Dollar, Indian Rupee, Pakistani Rupee, Russian Ruble, Mexican Peso
    float input;
    const float curr_amount[6] = {1, 0.62, 73.54, 278.82, 87.55, 19.898};

    printf("Enter Currency Amount: ");
    scanf("%f", &input);
    printf("%-6s | %-6s | %-6s | %-6s | %-6s | %-6s | %-6s\n"," ", "USD", "NZD", "INR", "PKR", "RUB", "MXN");

    // Nested Loop for each currency
    for (int i = 0; i < num_currencies; i++) {
        printf("%-6s |", currencies[i]); // Print the current currency
        for (int j = 0; j < num_currencies; j++) {
            float converted = convert(curr_amount[i], curr_amount[j], input);
            printf(" %6.2f |", converted); // Print the converted amount with fixed width of 6.2
        }
        printf("\n"); // New line after each currency
    }
}