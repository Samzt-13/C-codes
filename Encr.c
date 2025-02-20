//Making a message Encrypter & decrypter
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char text[500];
    int key, i, len, choice;

    printf("MAIN MENU\n");
    printf("Message Encrypter & Decrypter\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");    
    scanf("%d", &choice);

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter your key: ");
    scanf("%d, &key");

    len = strlen(text);

    if(choice == 1){
        for( i = 0; i< len; i++){
            text[i] = text[i] + key;
        }
    }    

    return 0;
}