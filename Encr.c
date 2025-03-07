// Making a message Encrypter & Decrypter
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Encrypt(char *text, int len, int k);
void Decrypt(char *text, int len, int k);

int main() {
    char *text = (char *)malloc(500 * sizeof(char));
    int key, len, choice;

    if (text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("MAIN MENU\n");
    printf("Message Encrypter & Decrypter\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    scanf("%d", &choice);
    while ((getchar()) != '\n'); // Clear input buffer

    switch (choice) {
        case 1:
            printf("Enter a message: ");
            fgets(text, 500, stdin);
            printf("Enter your key: ");
            scanf("%d", &key);

            len = strlen(text);
            Encrypt(text, len, key);
            printf("Encrypted message: %s\n", text);
            break;

        case 2:
            printf("Enter a message: ");
            fgets(text, 500, stdin);
            printf("Enter your key: ");
            scanf("%d", &key);

            len = strlen(text);
            Decrypt(text, len, key);
            printf("Decrypted message: %s\n", text);
            break;

        case 3:
            printf("Thanks for using the program\n");
            free(text);
            exit(0);

        default:
            printf("Invalid choice\n");
            printf("Please try again\n");
            break;
    }

    free(text);
    return 0;
}

void Encrypt(char *text, int len, int k) {
    for (int i = 0; i < len; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] + k;
            if (text[i] > 'z') {
                text[i] = text[i] - 'z' + 'a' - 1;
            }
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = text[i] + k;
            if (text[i] > 'Z') {
                text[i] = text[i] - 'Z' + 'A' - 1;
            }
        }
    }
}

void Decrypt(char *text, int len, int k) {
    for (int i = 0; i < len; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] - k;
            if (text[i] < 'a') {
                text[i] = text[i] + 'z' - 'a' + 1;
            }
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = text[i] - k;
            if (text[i] < 'A') {
                text[i] = text[i] + 'Z' - 'A' + 1;
            }
        }
    }
}
