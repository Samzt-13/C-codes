#include <stdio.h>   //header files
#include <string.h>
#include <stdlib.h>
//preprocessor directives
void menu(void);
void newStudent(void);
void displayStudents(void);
void searchStudent(void);
void updateMark(void);
void deleteStudent(void);
#define UNDERLINE "\033[1;21m"   //ASCII Code for an underline
#define RESET "\033[0m"   //ASCII Code to reset it to normal
//defining struct for student
typedef struct{
    char name[100];
    char surName[100];
    int age;
    int rollNO;
    int marks[5];
} Student;
//main function
int main(){
  while(1){   //while loop until you exit from it
  menu();
  }
  return 0; 
}
//print the menu & use switch for user wished functions
void menu(){
  int User_Choice;
  printf(UNDERLINE"\n\t\t\t\tSTUDENT GRADE MANAGEMENT\n");  //Just "Underline" for some good display
  printf("------MAIN MENU\n");
  printf("1.Add New Student\n");
  printf("2.Display Students\n");
  printf("3.Search Student\n");
  printf("4.Update Student Marks\n");
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
      updateMark();     //Function to update a student's marks
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
  for(int i = 0; i < 5; i++){
    printf("Enter his marks in Subject%d: ", i + 1);
    if(scanf("%d", &S1.marks[i])== 0){
      fprintf(stderr, "Invalid input provided!!!\n");
      exit(0);
    }
  }     
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
        printf("Name: %s %s\nAge: %d\nRoll No: %d\n", S1.name, S1.surName, S1.age, S1.rollNO);    //printing details
        for(int i = 0; i < 5; i++){
          printf("Marks in Subject %d: %d\n", i + 1, S1.marks[i]);   //for loop as we havr to print marks in every subject
        }
      }
    }
  }
  fclose(Std);    //closing the file to avoid leaks
}

void searchStudent(void){
  int rollNo, count = 0;   //rollNo for user input & count to see how many times the user input is equal to Student data
  FILE *Std;
  Student S1;
  Std = fopen("Student_Details.txt", "r");   //opening the file in read mode
  if(Std == NULL){
    fprintf(stderr, "Error in opening the file!!!\n");   //error message if the file is NULL
  }
  else{
  printf("\nSTUDENT SEARCH!\n");    //search for student detail
  printf("Enter his Roll No: ");
  if(scanf("%d", &rollNo) == 0){
    fprintf(stderr, "Invalid input provided!!!\n");
    exit(0);
  }
  while(feof(Std) == 0){
    if(fread(&S1, sizeof(Student), 1, Std) > 0){
      if(S1.rollNO == rollNo){
        printf("Name: %s %s\nAge: %d\nRoll No: %d\n", S1.name, S1.surName, S1.age, S1.rollNO);
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

void updateMark(void){
  printf("\nUpdate Student Marks!!!\n");
  
}

void deleteStudent(void){
  printf("Delete Students info here: ");
}