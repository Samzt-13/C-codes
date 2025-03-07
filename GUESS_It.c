#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void get_gamemode(int *);
int check_and_gen(int);

int main(){
    int number, user_guess, attempts = 0, game_mode;
    srand(time (0));
    printf("\t\t\t\t\tGUESS IT\n");
    printf("Welcome to \"Guess it\" its a guessing game\n");
    printf("You will be given hints. Just try to guess the number: \n");
    get_gamemode(&game_mode);
    number = check_and_gen(game_mode);
    do{
        printf("Guess a number: ");
        scanf("%d", &user_guess);
        attempts++;
        if(user_guess < number){
            printf("Guess a higher number\n");
        }
        else if(user_guess > number){
            printf("Guess a lower number\n");
        }
        else{
            printf("Congrats! You guessed it, it was %d\n", number);
            printf("Number of attempts taken: %d\n", attempts);
        }
    }
    while(user_guess != number);
    
    printf("Thanks for playing my time pass game\n");
    printf("Developed by--Samrat Parajuli\n");
    return 0;
}

void get_gamemode(int *a){
    int mode;
    printf("Enter game level first: \n");
    printf("Level 0: Very Easy\n");
    printf("Level 1: Easy\n");
    printf("Level 2: Normal\n");
    printf("Level 3: Hard\n");
    printf("Level 4: Very Hard\n");
    printf("Enter game level: ");
    scanf("%d", a);
    if(*a < 0 || *a > 4){
        printf("Invalid game level, please enter a valid game level\n");
        get_gamemode(&mode);
    }
}

int check_and_gen(int x){
    int number;
    switch(x){
        case 0:{
           number = rand() % 11 + 0;
           printf("Guess a number between 0 and 10\n");
           break;
        }
        case 1:{
             number = rand() % 51 + 0;
             printf("Guess a number between 0 and 50\n");
             break;
            }
        case 2:{
             number = rand() % 100 + 1;
             printf("Guess a number between 1 and 100\n");
             break;
            }
        case 3:{
             number = rand() % 200 + 1; 
             printf("Guess a number between 1 and 200\n");
             break;
            }
        case 4:{
             number = rand() % 500 + 1;
             printf("Guess a number between 1 and 500\n");
             break;
            }
    }
    return number;
}