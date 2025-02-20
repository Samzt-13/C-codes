#include <stdio.h>
#include <math.h>

void Sum(double, double);
void Diff(double, double);
void Mult(double, double);
void Div(double, double);
void power(double, int);
void factorial(double);

int main(){
    double operand1, operand2;
    char operator;

    printf("\t\t\tSimple Calculator\n");    //title
    //ask for an operator
    printf("Enter an operator(+, -. *, /, ^, !): ");
    scanf("%c", &operator);
    //switch statement for operator
    switch(operator){
        case '+':{
            printf("Enter two numbers: ");
            scanf("%lf %lf", &operand1, &operand2);
            Sum(operand1, operand2);
            break;
        }
            //sum of two numbers
        case '-':{
            printf("Enter two numbers: ");
            scanf("%lf %lf", &operand1, &operand2);
            Diff(operand1, operand2);
            break;
        }
            //difference of two numbers
        case '*':{
            printf("Enter two numbers: ");
            scanf("%lf %lf", &operand1, &operand2);
            Mult(operand1, operand2);
            break;
        }
            //product of two numbers
        case '/':{
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
        case '^': {
            printf("Enter a number: ");
            scanf("%lf", &operand1);
            printf("What power do you want to raise it to? ");
            scanf("%d", &operand2);
            power(operand1, operand2);
            break;
        }
        case '!':{
            printf("Enter a number: ");
            scanf("%lf", &operand1);
            factorial(operand1);
            break;
        }
        default:
            printf("Error!!!Invalid operator.");
            //default case
    }
    printf("\nEnd of the program.");
    return 0;
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