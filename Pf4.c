#include <stdio.h>

#define MAX_SIZE 100

void findCharFrequency(const char *inputString);

int main() {
    char inputString[MAX_SIZE];

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    findCharFrequency(inputString);

    return 0;
}

void findCharFrequency(const char *inputString) {
    int characterFrequency[26] = {0};

    for (int i = 0; inputString[i] != '\0'; i++) {
        char currentChar = inputString[i];
        if (currentChar >= 'a' && currentChar <= 'z') {
            int index = currentChar - 'a';
            characterFrequency[index]++;
        }
    }

    printf("Character frequency:\n");
    for (int i = 0; i < 26; i++) {
        if (characterFrequency[i] > 0) {
            printf("%c: %d\n", 'a' + i, characterFrequency[i]);
        }
    }
}
