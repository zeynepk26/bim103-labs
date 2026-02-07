#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generateRandomNumbers(int* n1, int* n2);
int bruteForceGCD(int a, int b);
int euclideanGCD(int a, int b);

int main() {
    srand(time(NULL));

    int num1, num2;
    int choice, result;

    generateRandomNumbers(&num1, &num2);

    printf("generated numbers: %d and %d\n", num1, num2);
    printf("--------------------------------\n");
    printf("select GCD algorithm:\n");
    printf("1 = brute force algorithm\n");
    printf("2 = euclidean algorithm\n");
    printf("choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        result = bruteForceGCD(num1, num2);
        printf("result (brute force): %d\n", result);
    }
    else if (choice == 2) {
        result = euclideanGCD(num1, num2);
        printf("result (euclidean): %d\n", result);
    }
    else {
        printf("invalid choice! please restart the program.\n");
    }

    return 0;
}

void generateRandomNumbers(int* n1, int* n2) {
    *n1 = (rand() % 1000) + 1;
    *n2 = (rand() % 1000) + 1;
}

int bruteForceGCD(int a, int b) {
    int gcd = 1;
    int limit = (a < b) ? a : b;

    for (int i = 1; i <= limit; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}    

int euclideanGCD(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int k = a % b;

    while (k != 0) {
        a = b;
        b = k;
        k = a % b;
    }
    return b;
}