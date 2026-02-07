#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void analyzeSentence(char** strPtr, int* vowels, int* words);
int findIndex(char* str, char target);
void reverseString(char* str);
void convertToUpper(char* str);

int main() {
    char sentence[100];
    char searchChar;
    char* pSent = sentence;
    char** doublePtr;
    char reversedSent[100];
    char upperReversedSent[100];

    printf("Sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        sentence[strcspn(sentence, "\n")] = 0;
    }

    printf("Character to Search: ");
    scanf(" %c", &searchChar);

    int numVowels = 0;
    int numWords = 0;
    doublePtr = &pSent;

    analyzeSentence(doublePtr, &numVowels, &numWords);

    size_t sentLength = strlen(sentence);

    int charIndex = findIndex(sentence, searchChar);

    strcpy(reversedSent, sentence);
    reverseString(reversedSent);
    strcpy(upperReversedSent, reversedSent);
    convertToUpper(upperReversedSent);

    printf("Sentence Length: %zu\n", sentLength);
    printf("Number of Vowels: %d\n", numVowels);
    // printf("Number of Words: %d\n", numWords);
    printf("Character '%c' Found: %s\n", searchChar, (charIndex != -1) ? "Yes" : "No");
    printf("First Occurrence Index: %d\n", charIndex);
    printf("Reversed Sentence: %s\n", reversedSent);
    printf("Uppercase Reversed Sentence: %s\n", upperReversedSent);
    printf("Mirror: %-30s | %30s\n", sentence, reversedSent);

    return 0;
}

void analyzeSentence(char** strPtr, int* vowels, int* words) {

    char* temp = *strPtr;
    char* start = *strPtr;

    while (*temp != '\0') {
        if (strchr("aeiouAEIOU", *temp)) {
            (*vowels)++;
        }

        if (*temp != ' ') {
            if (temp == start || *(temp - 1) == ' ') {
                (*words)++;
            }
        }

        temp++;
    }
}

int findIndex(char* str, char target) {
    char* resultPtr = strchr(str, target);

    if (resultPtr != NULL) {
        return (int)(resultPtr - str);
    }
    else {
        return -1;
    }
}

void reverseString(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void convertToUpper(char* str) {
    char* temp = str;
    while (*temp != '\0') {
        *temp = toupper(*temp);
        temp++;
    }
}