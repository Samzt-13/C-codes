#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int PrintMenu();

void Sum(double, double);
void Diff(double, double);
void Mult(double, double);
void Div(double, double);
void power(double, int);
void factorial(double);

int main(){
    double operand1, operand2;
    int power_call;
    char operator = 1;

    operator = PrintMenu(); //get the operator & print the menu
    //switch statement for operator
    switch(operator){
        case 1:{
            printf("Enter two numbers: ");
            scanf("%lf %lf", &operand1, &operand2);
            Sum(operand1, operand2);
            break;
        }
            //sum of two numbers
        case 2:{
            printf("Enter two numbers: ");
            scanf("%lf %lf", &operand1, &operand2);
            Diff(operand1, operand2);
            break;
        }
            //difference of two numbers
        case 3:{
            printf("Enter two numbers: ");
            scanf("%lf %lf", &operand1, &operand2);
            Mult(operand1, operand2);
            break;
        }
            //product of two numbers
        case 4:{
            printf("Enter two numbers: ");
            scanf("%lf %lf", &operand1, &operand2);
            if(operand2 != 0){
            Div(operand1, operand2);
            }
            //show error if second operand is 0
            else{
                printf("Error!!! Division by zero is not allowed.");
            }
            break;
        }
        //division of two numbers
        case 5: {
            printf("Enter a number: ");
            scanf("%lf", &operand1);
            printf("What power do you want to raise it to? ");
            scanf("%d", &power_call);//get the power from user
            power(operand1, power_call);  //call the power function
            break;
        }
        case 6:{
            printf("Enter a number: ");
            scanf("%lf", &operand1);
            factorial(operand1);
            break;
        }
        case 7:{
            printf("Exiting the program.");
            exit(0);
            break;
        }
        default:
            printf("Error!!!Invalid operator.\n");
            exit(0);
            //default case
    }
    printf("\nThanks for using the calculator.\n");
    printf("Developed by: Samrat Parajuli");
    return 0;
}

//function to print main menu
int PrintMenu(){
    int choice;
    printf("\t\t\tSimple Calculator\n");    //title
    printf("What do you wish to do?\n");
    printf("1.Addition\n");
    printf("2.Subtraction\n");  
    printf("3.Multiplication\n");
    printf("4.Division\n"); 
    printf("5.Power\n");
    printf("6.Factorial\n");    
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}
//functions for each operator
void Sum(double a, double b){
    double Sum = a + b;
    printf("%.2lf + %.2lf = %.2lf", a, b, Sum);
}
void Diff(double a, double b){
    double diff = a - b;
    printf("%.2lf - %.2lf = %.2lf", a, b, diff);
}
void Mult(double a, double b){
    double mult = a * b;
    printf("%.2lf x %.2lf = %.2lf", a, b, mult);
}
void Div(double a, double b){
    double div = a / b;
    printf("%.2lf / %.2lf = %.2lf", a, b, div);
}

void power(double a, int b){
    double result = pow(a, b);
    printf("%.2lf ^ %d = %.2lf", a, b, result);
}
void factorial(double a){
    double fact = 1;
    for(int i = 1; i <= a; i++){
        fact *= i;
    }
    printf("%.2lf! = %.2lf", a, fact);
}