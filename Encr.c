//Making a message Encrypter & decrypter
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Encrypt(char *, int, int);
void Decrypt(char *, int, int);

int main(){
    char * text[500];
    int key, i, len, choice;

    printf("MAIN MENU\n");
    printf("Message Encrypter & Decrypter\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");    
    scanf("%d", &choice);

    * text = (int *)malloc(500 * sizeof(int));

    if(choice == 1){
        printf("Enter a message: ");
        fgets(text, sizeof(text), stdin);

        printf("Enter your key: ");
        scanf("%d, &key");

        len = strlen(text);

       Encrypt(text, len, key);
    }    
    else if(choice == 2){
        printf("Enter a message: ");
        fgets(text, 500, stdin);

        printf("Enter your key: ");
        scanf("%d, &key");

        len = strlen(text);

        Decrypt(text, len, key);
    }
    else if(choice == 3){
        printf("Thanks for using the program\n");
        exit(0);
    }
    else{
        printf("Invalid choice\n");
        printf("Please try again\n");
    }

    free(text);

    return 0;
}

void Encrypt(char *text, int len, int k){
    int i;
    for(i = 0; i < len; i++){
        if(*(text + i) >= 'a' &&*(text + i) <= 'z'){
            text[i] = text[i] + k;
            if(text[i] > 'z'){
                text[i] = text[i] - 'z' + 'a' - 1;
            }
        }
        else if(*(text + i) >= 'A' && *(text + i) <= 'Z'){
            text[i] = text[i] + k;
            if(text[i] > 'Z'){
                text[i] = text[i] - 'Z' + 'A' - 1;
            }
        }
        printf("%c", text[i]);
    }
    printf("Encrypted message: %s\n", text);
}

void Decrypt(char* text, int len, int k){
    int i;
    for(i = 0; i < len; i++){
        if(*(text + i) >= 'a' && *(text + i) <= 'z'){
            text[i] = text[i] - k;
            if(text[i] < 'a'){
                text[i] = text[i] + 'z' - 'a' + 1;
            }
        }
        else if(*(text + i) >= 'A' && *(text + i) <= 'Z'){
            text[i] = text[i] - k;
            if(text[i] < 'A'){
                text[i] = text[i] + 'Z' - 'A' + 1;
            }
        }
        printf("%c", text[i]);
    }
}