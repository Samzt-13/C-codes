#include <stdio.h>   //header files
#include <string.h>
#include <stdlib.h>
//preprocessor directives
void menu(void);
void newStudent(void);
void displayStudents(void);
void searchStudent(void);
void updateStudent(void);
void deleteStudent(void);
#define UNDERLINE "\033[1;21m"   //ASCII Code for an underline
#define RESET "\033[0m"   //ASCII Code to reset it to normal
//defining struct for student
typedef struct{
    char name[100];
    char surName[100];
    int age, rollNO, number;
    char course[50];
} Student;
//main function
int main(){
  while(1){  //while loop until you exit from it
  menu();
  }
  return 0; 
}
//print the menu & use switch for user wished functions
void menu(){
  int User_Choice;
  printf(UNDERLINE"\n\t\t\t\tSTUDENT GRADE MANAGEMENT\n");  //Just "Underline" for some good display
  printf("\n\n\t\t\t\t>>>-----MAIN MENU-----<<<\n");
  printf("1.Add New Student\n");
  printf("2.Display Students\n");
  printf("3.Search Student\n");
  printf("4.Update Student\n");
  printf("5.Delete Student\n");
  printf("6.Exit\n");
  printf("Enter your choice: ");
  if(scanf("%d", &User_Choice) == 0){
      fprintf(stderr, "Error Input Provided!!!!");
  }
  switch(User_Choice){
    case 1:{
      newStudent();  //Function for registering New Student
      break;
    }

    case 2:{
      displayStudents();  //Function to Display Students
      break;
    }

    case 3:{
      searchStudent();    //Function to Search for a Student
      break;
    }

    case 4:{
      updateStudent();     //Function to update a student's marks
      break;
    }

    case 5:{
      deleteStudent();    //Function to delete any student
      break;
    }

    case 6:{
      printf("Exiting the program!!\n");
      printf("Thanks for using it");
      printf("Developed by --Samrat Parajuli");
      printf(RESET);   //reset the color to normal 
      exit(0);
      break;
    }

    default:{
        fprintf(stderr, "Error!!\nIvalid Input Provided!\n");
    }
  }
}

void newStudent(void){
  system("cls");
  printf("\t\t\t:::NEW STUDENT:::");
  printf("\n\n\n");
  Student S1;     //giving name to the struct
  FILE *Std;   //declaring the file
  Std = fopen("Student_Details.txt", "a");   //oprning the file in "append mode"
  if(Std == NULL){
    fprintf(stderr, "File Execution unsuccessfull!\n");
    return;
  }
  else{
  printf("New Student: \n");
  printf("Enter his name: ");
  scanf("%s", S1.name);
  printf("Enter his surname: ");
  scanf("%s", S1.surName);
  printf("Enter his age: ");
  if(scanf("%d", &S1.age) == 0){
    fprintf(stderr, "Invalid input provided!!!\n");
    exit(0);
  }
  printf("Enter his Roll No: ");
  if(scanf("%d", &S1.rollNO) == 0){
    fprintf(stderr, "Invalid input provided!!!\n");
    exit(0);
  }
  printf("Enter his phone number: ");
  if(scanf("%d", &S1.number) == 0){
    fprintf(stderr, "Invalid input provided!!!\n");
    exit(0);
  }
  printf("Enter his course name: ");
  scanf("%s", S1.course);     
  if(fwrite(&S1, sizeof(Student), 1, Std) > 0){
    printf("Data Registered Successfully!\n");
  }
  else{
    fprintf(stderr, "Data Registration Error!!!\n");
  }
  }
  fclose(Std);
}

void displayStudents(){
  printf("\t\t\t:::STUDENT DISPLAY:::");
  printf("\n\n\n");
  printf("\nStudent Details: \n");
  FILE *Std;
  Student S1;
  Std = fopen("Student_Details.txt", "r");   //file opening in read mode
  if(Std == NULL){
    fprintf(stderr, "File Open Error!!!\n");
  }
  else{
    while(feof(Std) == 0){     //while the end of the file has been reached
      if(fread(&S1, sizeof(Student), 1, Std) > 0){   //if the data we read from the file is not symbols
        printf("\nName: %s %s\nAge: %d\nRoll No: %d\nPhone: %d\nCourse: %s\n", S1.name, S1.surName, S1.age, S1.rollNO, S1.number, S1.course);    //printing details
      }
      printf("\n");
    }
  }
  fclose(Std);    //closing the file to avoid leaks
}

void searchStudent(void){
  system("cls");
  printf("\t\t\t:::STUDENT SEARCH:::");
  printf("\n\n\n");
  int count = 0;   //count to see how many times the user input is equal to Student data
  char name[100]; 
  FILE *Std;
  Student S1;
  Std = fopen("Student_Details.txt", "r");   //opening the file in read mode
  if(Std == NULL){
    fprintf(stderr, "Error in opening the file!!!\n");   //error message if the file is NULL
  }
  else{
  printf("\nSTUDENT SEARCH!\n");    //search for student detail
  printf("Enter his Roll No: ");
  scanf("%s", name);
  while(feof(Std) == 0){
    if(fread(&S1, sizeof(Student), 1, Std) > 0){
      if((strcmp(S1.name, name)) == 0){
        printf("Name: %s %s\nAge: %d\nRoll No: %d\nPhone Number: %d\nCourse: %s\n", S1.name, S1.surName, S1.age, S1.rollNO, S1.number, S1.course);
        count++;
      }
    }
   }
   if(count < 1){
      printf("Student Not Found!!!\n");
   }
  }
  fclose(Std);
}

void updateStudent(void){
  system("cls");
  printf("\n\n\n");
  char name[100];
  char newName[100], surName[100], course[50];
  int age, rollNo, phoneNumber;
  FILE *Std;
  Student S1;
  Std = fopen("Student_Details.txt", "r+");
  printf("\nUpdate Student Details!!!\n");
  printf("Enter his name to proceed: \n");
  scanf("%s", name);
  while(feof(Std) == 0){
    if(fread(&S1, sizeof(Student), 1, Std) > 0){
      if((strcmp(S1.name, name)) == 0){
          printf("Enter his new detail: ");
          printf("FUll Name: ");
          scanf("%s %s", newName, surName);
          printf("Enter his new Age: ");
          scanf("%d", &age);
          printf("Enter his new Roll No: ");
          scanf("%d", &rollNo);
          printf("Enter his new Phone Number: ");
          scanf("%d", &phoneNumber);
          printf("Enter his new course: ");
          scanf("%s", course);
        }
    }
  }
  fclose(Std);
}

void deleteStudent(void){
  printf("Delete Students info here: ");
}