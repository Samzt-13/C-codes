#include <stdio.h>
#include <math.h>

void Sum(double, double);
void Diff(double, double);
void Mult(double, double);
void Div(double, double);

int main(){
    double operand1, operand2;
    char operator;

    printf("Enter an operator(+, -. *, /): ");
    scanf("%c", &operator);

    printf("Enter the first number: ");
    scanf("%lf", &operand1);

    printf("Enter another number: ");
    scanf("%lf", &operand2);

    switch(operator){
        case '+':
            Sum(operand1, operand2);
            break;
        case '-':
            Diff(operand1, operand2);
            break;

        case '*':
            Mult(operand1, operand2);
            break;

        case '/':
            Div(operand1, operand2);
            break;

        default:
            printf("Error!!!");
    }

    return 0;
}

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