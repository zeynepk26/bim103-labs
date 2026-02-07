#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define SIZE 20 
#define RANDOM_SEED 42

// swap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort function
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void findAndPrintClosestPair(int arr[], int n, int target) {
    int i, j;
    int currentSum, currentDiff;
    int minDiff = INT_MAX;
    int bestVal1 = 0, bestVal2 = 0, bestSum = 0;

    // algorithm to find the closest pair
    // outer loop: select the first number
    for (i = 0; i < n - 1; i++) {
        // inner loop: select the second number
        for (j = i + 1; j < n; j++) {
            currentSum = arr[i] + arr[j];
            currentDiff = abs(target - currentSum);

            if (currentDiff < minDiff) {
                minDiff = currentDiff;
                bestVal1 = arr[i];
                bestVal2 = arr[j];
                bestSum = currentSum;
            }
        }
    }

    // print results
    printf("Target Sum: %d\n\n", target);
    printf("Closest Pair: %d and %d\n\n", bestVal1, bestVal2);
    printf("Pair Sum: %d\n\n", bestSum);
    printf("Minimum Absolute Difference to Target: %d\n\n", minDiff);
}

int main(void) {
    int values[SIZE];
    int i;
    int targetSum;

    // seed setting 
    srand(RANDOM_SEED);

    // fill the array with random numbers
    for (i = 0; i < SIZE; i++) {
        values[i] = 1 + rand() % 100;
    }

    // sort the array
    bubbleSort(values, SIZE);

    // print the sorted array
    printf("Sorted Array: \n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", values[i]);
    }
    printf("\n\n");

    // input from user
    printf("Enter Target Sum: ");

    // input validation using if-else
    if (scanf("%d", &targetSum) == 1) {
        printf("\n");
        findAndPrintClosestPair(values, SIZE, targetSum);
    }
    else {
        printf("\n\nError: Invalid input! Please enter a valid integer number.\n");
    }

    return 0;
}