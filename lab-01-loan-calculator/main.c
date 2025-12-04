#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double amount;
    int remainingAmount;
    int dollars, quarters, dimes, nickels, pennies;

    // input
    printf("Enter an amount in double, for example 11.56: ");
    scanf("%lf", &amount);

    remainingAmount = (int)(amount * 100 + 0.001);

    // dollars (100 cents)
    dollars = remainingAmount / 100;
    remainingAmount = remainingAmount % 100;

    // quarters (25 cents)
    quarters = remainingAmount / 25;
    remainingAmount = remainingAmount % 25;

    // dimes (10 cents)
    dimes = remainingAmount / 10;
    remainingAmount = remainingAmount % 10;

    // nickels (5 cents)
    nickels = remainingAmount / 5;
    remainingAmount = remainingAmount % 5;

    // pennies (1 cent)
    pennies = remainingAmount;

    // print
    printf("Your amount %.2f consists of\n", amount);
    printf("%d dollars\n", dollars);
    printf("%d quarters\n", quarters);
    printf("%d dimes\n", dimes);
    printf("%d nickels\n", nickels);
    printf("%d pennies\n", pennies);

    return 0;
}