#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int menu();
void fill_time(char *, int);
void printDate(void);
void checkOpt(int);

int main(){
        char time[50];
        int format = menu(), count = 0;
    while(1){
        fill_time(time, format);
        printf("Current Time: %s", time);
        printDate();
        printf("\n\n\n\n\n\t\t\t\t");
        count++;
        if(count == 30){
            int opt;
            printf("OPTIONS: \n1.Continue\n2.Stop\n3.Exit\n");
            if((scanf("%d", &opt)) == 0){
                fprintf(stderr, "Invalid Input Provided!!!\n");
                exit(0);
            }
            checkOpt(opt);
            count = 0;
        }
        sleep(1);
    }
    return 0;
}

int menu(){
    printf("\n\n\n\n\n\t\t\t\t");
    int format;
    printf("\n\t\t\t\t\tDIGITAL CLOCK\n");
    printf("Enter time format: \n");
    printf("1.Default(12 Hr): \n");
    printf("2.24 Hours: \n: ");
    if((scanf("%d", &format)) == 0){
        fprintf(stderr, "Invalid Input Provided!!!\n");
        exit(0);
    }
    return format;
}

void fill_time(char *buffer, int format){
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t");
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);
    switch(format){
        case 1:{
            strftime(buffer, 50, "%I:%M:%S %p", current_time);
            break;
        }
        case 2:{
            strftime(buffer, 50, "%H:%M:%S", current_time);
            break;
        }
        default: {
            printf("Error!! Wrong format type!!!!");
            exit(0);
        }
    }
}

void checkOpt(int a){
    switch(a){
        case 1:{
            sleep(1);
            break;
        }

        case 2:{
            printf("Closing the clock for a while!!!\n\n");
            system("pause");
            break;
        }

        case 3:{
            printf("Exiting the clock!!");
            exit(0);
            break;
        }

        default:{
            fprintf(stderr, "Invalid Options!!");
            exit(0);
        }
    }
}

void printDate(void){
    char date[50], buffer[50];
    time_t rawDate;
    
    struct tm *currentDate;
    time(&rawDate);
    currentDate = localtime(&rawDate);
    strftime(buffer, 50, "%A, %B, %d %Y", currentDate);
    printf("\n\t\t\t\tDate: %s", buffer);
}