#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int PrintMenu();

void Sum(double, double);
void Diff(double, double);
void Mult(double, double);
void Div(double, double);
void power(double, int);
void factorial(int);
void SquareRoot(void);
void Trigonometry(void);

double to_radians(double);

#define M_PI 3.14159265358979323846

int main(){
    double operand1, operand2;
    int power_call, facto_user; //define power_call for power & facto_user to get factorial from user as an integer
    int operator = 1;
    while(1){
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
            scanf("%d", &facto_user);
            factorial(facto_user);
            break;
        }
        case 7:{
            SquareRoot();
            break;
        }
        case 8:{
            Trigonometry();
            break;
        }
        case 9:{
            printf("Exiting the program.");
            printf("\nThanks for using the calculator.\n");
            printf("Developed by: Samrat Parajuli");
            printf("\n\t\t\t\t\tTHE END\n");
            exit(0);
        }
        default:
            fprintf(stderr, "Error!!!Invalid operator.\n");
            continue;            //default case
    }
    }
    return 0;
}

//function to print main menu
int PrintMenu(){
    int choice;
    printf("\n\t\t\t\t\tSimple Calculator\n");    //title
    printf("What do you wish to do?\n");
    printf("1.Addition\n");
    printf("2.Subtraction\n");  
    printf("3.Multiplication\n");
    printf("4.Division\n"); 
    printf("5.Power\n");
    printf("6.Factorial\n");
    printf("7.Square Root\n");
    printf("8.Trigonometric Calculation\n");
    printf("9.Exit\n");
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
void factorial(int a){
    double fact = 1;
    if (a < 0) {
        printf("Error! Factorial of a negative number doesn't exist.\n");
        return;
    }
    for(int i = 1; i <= a; i++){
        fact *= i;
    }
    printf("%d! = %.2lf\n", a, fact);
}

void SquareRoot(){
    int number;
    double result;
    printf("Enter a number: ");
    scanf("%d", &number);
    result = sqrt(number);
    printf("Square Root of %d is: %.2lf", number, result);
}

void Trigonometry(){
    int choice;
    double angle, result;
    printf("What type of Trigonometric Calculation do you want to do?\n");
    printf("1.Sine\n");
    printf("2.Cosine\n");
    printf("3.Tangent\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter your angle: ");
    scanf("%lf", &angle);
    switch(choice){
        case 1:{
            result = sin(to_radians(angle));
            printf("Sine(%.2lf) = %.2lf\n", angle, result);
            break;
        }

        case 2:{
            result = cos(to_radians(angle));
            printf("Cosine(%.2lf) = %.2lf\n", angle, result);
            break;
        }

        case 3:{
            result = tan(to_radians(angle));
            if(result < -1 || result > 1){
                printf("tan(%.2lf) = Undefine\n", angle);
            }
            else{
            printf("tan(%.2lf) = %.2lf\n", angle, result);
            }
            break;
        }

        default:{
            printf("Invalid choice.\n");
            break;
        }
    }
}

double to_radians(double num){
    double fun_result = num * M_PI / 180;
    return fun_result;
}