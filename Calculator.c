#include <stdio.h>  //for printf() & scanf() functions
#define _USE_MATH_DEFINES //to use M_PI function
#include <math.h>  //for advanced mathematic calculation
#include <stdlib.h>  //for functions like exit(0)

int printMenu();  //main menu for the UI
//all the function prototypes here
void basicOperations(void);
void trigonometricCalculations(void);
void advancedCalculations(void);
void sumOperation(double, double);
void differenceOperation(double, double);
void mult(double, double);
void divOperation(double, double);
void power(double, int);
void factorial(int);
void squareRoot(void);
void trigonometryCalc(void);
double to_radians(double);
void unitConversion(void);
void lengthConversion(void);
void weightConversion(void);
void tempConversion(void);
void checkPalindrome(void);
void printFibonacci(void);
void logarithmicFunctions(void);
void fib(int);
//these two for the Underline on the code & reseting it to normal
#define RESET "\033[0m"
#define UNDERLINE "\033[1;21m"
//main part of the function
int main(){
    int operator = 1;
    while(1){
    operator = printMenu(); //get the operator & print the menu
    //switch statement for operator
    switch(operator){
        case 1:{
            basicOperations(); //for basic calculations
            break;
        }

        case 2:{
            trigonometricCalculations();  //for trigonometric calculations
            break;
        }

        case 3:{
            advancedCalculations();  //for advanced calculations
            break;
        }

        case 4:{
            //messages for exiting the program 
            printf("Exiting the program.");
            printf("\nThanks for using the calculator.\n");
            printf("Developed by: Samrat Parajuli");
            printf("\n\t\t\t\t\tTHE END\n");
            printf(RESET);
            exit(0);  //exits from the while loop. Lies in <stdlib.h> header file
        }
        default:{
            fprintf(stderr, "Error!!!Invalid operator.\n");  //shows the wrong user input
            continue;            //default case
    }
    }
}
    return 0;
}

//function to print main menu
int printMenu(){
    int choice;
    printf(UNDERLINE"\n\t\t\t\t\tINTERMEDIATE LEVEL CALCULATOR\n");    //title
    printf("What do you wish to do?\n");
    printf("1.Basic Operations: \n");
    printf("2.Trigonometric Operations: \n");
    printf("3.Advanced Calculations: \n");
    printf("4.Exit\n");
    printf("Enter your choice: ");
    if((scanf("%d", &choice)) == 0){
        printf("Inavlid Operation!!!!");  //handling errors if user input something different from number
        exit(0);  //directly exits the while loop in the main function
    }

    return choice;
}
void basicOperations(void){
    int Basic_choice, power_call, facto_user;  //define power_call for power & facto_user to get factorial from user as an integer
    double operand1, operand2;
    printf("\t\t\t\t\tBASIC CALCULATION\n");
    printf("1.Addition: \n");
    printf("2.Subtraction: \n");
    printf("3.Multiplication: \n");
    printf("4.Division: \n");
    printf("5.Power: \n");
    printf("6.Factorial: \n");
    printf("7.Square Root: \n");
    printf("Choose one operation: ");
    if((scanf("%d", &Basic_choice)) == 0){
        printf("Inavlid Operation!!!!");  //same as before (just handling user input errors)
        exit(0);
    }
    switch(Basic_choice){
        case 1:{
            printf("Enter two numbers: ");
            scanf("%lf %lf", &operand1, &operand2);
            sumOperation(operand1, operand2);
            break;
        }
            //sum of two numbers
        case 2:{
            printf("Enter two numbers: ");
            scanf("%lf %lf", &operand1, &operand2);
            differenceOperation(operand1, operand2);
            break;
        }
            //difference of two numbers
        case 3:{
            printf("Enter two numbers: ");
            scanf("%lf %lf", &operand1, &operand2);
            mult(operand1, operand2);
            break;
        }
            //product of two numbers
        case 4:{
            printf("Enter two numbers: ");
            scanf("%lf %lf", &operand1, &operand2);
            if(operand2 != 0){
            divOperation(operand1, operand2);
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
            squareRoot();
            break;
        }

        default:{
            fprintf(stderr, "Invalid Operation!!! ");
            exit(0);  //exits the while loop for invalid input
        }
    }
}
//for trigonometric calculations
void trigonometricCalculations(void){
    printf("\t\t\t\t\tTRIGONOMETRIC CALCULATION\n");  //just some UI, not compulsory
    trigonometryCalc();
}

void advancedCalculations(){
    int Advance_Call;  //for the user choice input
    printf("\t\t\t\t\tADVANCED CALCULATION\n"); //just some UI, not compulsory
    printf("1.Unit Conversion: \n");
    printf("2.Palindrome: \n");
    printf("3.Fibonacci: \n");;
    printf("4.Logarithm: \n");
    printf("Choose one operation: ");
    if((scanf("%d", &Advance_Call)) == 0){
        fprintf(stderr, "Inavlid Operation!!!!"); //input error handling
        exit(0);
    }
    switch(Advance_Call){
        case 1:{
            unitConversion();
            break;
        }

        case 2:{
            checkPalindrome();
            break;
        }

        case 3:{
            printFibonacci();
            break;
        }

        case 4:{
            logarithmicFunctions();
            break;
        }

        default :{
            printf("Invalid Operation!!! ");
            exit(0);  //exists the while loop.
        }
    }
}
//functions for each operator
void sumOperation(double a, double b){
    double Sum = a + b;
    printf("%.2lf + %.2lf = %.2lf", a, b, Sum);
}
void differenceOperation(double a, double b){
    double diff = a - b;
    printf("%.2lf - %.2lf = %.2lf", a, b, diff);
}
void mult(double a, double b){
    double mult = a * b;
    printf("%.2lf x %.2lf = %.2lf", a, b, mult);
}
void divOperation(double a, double b){
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
        fprintf(stderr, "Error! Factorial of a negative number doesn't exist.\n");  //user input error handling
        return;
    }
    for(int i = 1; i <= a; i++){
        fact *= i;  //multiplying it until its done with a for loop
    }
    printf("%d! = %.2lf\n", a, fact);  //prints the factorial
}

void squareRoot(){
    int number;
    double result;
    printf("Enter a number: ");
    scanf("%d", &number);
    result = sqrt(number);
    printf("Square Root of %d is: %.2lf", number, result);
}

void trigonometryCalc(){
    int choice;
    double angle, result;
    printf("What type of Trigonometric Calculation do you want to do?\n");  //for some trigonometric calculations
    printf("1.Sine\n");
    printf("2.Cosine\n");
    printf("3.Tangent\n");
    printf("Enter your choice: ");
    if((scanf("%d", &choice)) == 0){
        fprintf(stderr, "Inavlid Operation!!!!"); //input error handling
        exit(0);
    }
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
//changes the angle to radian for <math.h> function to work
double to_radians(double num){
    double fun_result = num * M_PI / 180;
    return fun_result;
}
void unitConversion(void){
    int choice;

    printf("Welcome to Unit Conversion: \nWhat type of unit conversion do you want to do?\n"); //unit conversion for the user
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("Enter your choice: ");
    if((scanf("%d", &choice)) == 0){
        fprintf(stderr, "Inavlid Operation!!!!"); //input error handling
        exit(0);
    }

    switch (choice){
        case 1:{
            lengthConversion();
            break;
        }

        case 2:{
            weightConversion();
            break;
        }

        case 3:{
            tempConversion();
            break;
        }

        default:{
            break;
        }
    }
}

void lengthConversion(void){
    int choice;
    double value;
    
    printf("\nLength Converter\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Inches to Centimeters\n");
    printf("4. Centimeters to Inches\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%lf", &value);
    
    switch (choice) {
        case 1: printf("%.2lf meters = %.2lf kilometers\n", value, value / 1000); break;
        case 2: printf("%.2lf kilometers = %.2lf meters\n", value, value * 1000); break;        //just some basic stuff
        case 3: printf("%.2lf inches = %.2lf centimeters\n", value, value * 2.54); break;
        case 4: printf("%.2lf centimeters = %.2lf inches\n", value, value / 2.54); break;
        default: printf("Invalid choice.\n"); //handling default function
    }
}

void weightConversion(void){
        int choice;
        double value;
        
        printf("\nWeight Converter\n");
        printf("1. Kilograms to Pounds\n");
        printf("2. Pounds to Kilograms\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        printf("Enter value: ");
        scanf("%lf", &value);
        
        switch (choice) {
            case 1: printf("%.2lf kilograms = %.2lf pounds\n", value, value * 2.20462); break;
            case 2: printf("%.2lf pounds = %.2lf kilograms\n", value, value / 2.20462); break;
            default: printf("Invalid choice.\n");
        }
}
void tempConversion(void){
    int choice;
    double value;
    
    printf("\nTemperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%lf", &value);
    
    switch (choice) {
        case 1: printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, (value * 9/5) + 32); break;
        case 2: printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, (value - 32) * 5/9); break;
        default: printf("Invalid choice.\n");
    }
}
//check if its palindrome.
void checkPalindrome(void){
        int num, temp, reverse = 0;

        printf("Enter a number: ");
        scanf("%d", &num);
        temp = num;
        while(temp != 0){
            reverse = (reverse * 10) + temp % 10;
            temp = temp / 10;
        }
        if(reverse == num){
            printf("%d is a palindrome number\n", num);
        }
        else{
            printf("%d is not a palindrome number\n", num);
        }
}
//to print fibonacci numbers till the user input
void printFibonacci(void){
        int num, fibo;
        do{
            printf("Enter the Fibonacci print range: ");
            scanf("%d", &num);
        }
        while(num < 1);
        if(num == 1){
            printf("0");
        }
        else if(num == 2){
            printf("0\t1");
        }
        else if(num >= 48){  //just handling if user input is too big
            fprintf(stderr, "Please enter smaller number: ");  //error handling
        }
        else{
            fib(num);
        }
}
//to print fibonacci numbers
void fib(int num){
    int num1 = 0, num2 = 1, current;
    printf("%d\t%d\t", num1, num2);
    for(int i = 2; i < num; i++){
        current = num1 + num2;
        printf("%d\t", current);
        num1 = num2;
        num2 = current;
    }
    printf("\n");
}

void logarithmicFunctions(void){
    int num, logn, base, choice;
    printf("You can find the logarithm of any function here\n");
    printf("1.base 10\n");
    printf("2.base 2\n");
    printf("3.Custom base\n");
    printf("Enter your choice: ");
    if((scanf("%d", &choice)) == 0){ 
        fprintf(stderr, "Inavlid Operation!!!!"); //input error handling
        exit(0);
    }
    if(choice < 3){
        goto Here;
    }
    else{
    printf("Choose the custom base for log: ");
    scanf("%d", &base);
    }
    Here:
    printf("Enter a number: ");
    scanf("%d", &num);
    switch(choice){
        case 1:{
            logn = log10(num);  //find base 10 for number
            printf("Log(%d) = %d\n", num, logn);
            break;
        }

        case 2:{
            logn = log2(num); //find base 2 for number
            printf("Log(%d) = %d\n", num, logn);
            break;
        }

        case 3:{
            logn = log(num) / log(base);  //find the custom base
            printf("Log(%d) = %d\n", num, logn);
            break;
        }
        default:{
            fprintf(stderr, "Invalid Operation!!! ");
            exit(0);  //exits the while loop for invalid input
        }
    }
}