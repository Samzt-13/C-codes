#include <stdio.h>   //header files
#include <string.h>
#include <stdlib.h>
//preprocessor directives
void menu(void);
void New_Student(void);
void Display_Students(void);
void Search_Student(void);
void Update_Marks(void);
void Delete_Student(void);
#define UNDERLINE "\033[1;21m"   //ASCII Code for an underline
#define RESET "\033[0m"   //ASCII Code to reset it to normal
//defining struct for student
typedef struct{
    char name[100];
    char SurName[100];
    int Age;
    int Roll_No;
    int Marks[5];
} Student;
//main function
int main(){
  while(1){
  menu();
  }
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
      New_Student();  //Function for registering New Student
      break;
    }

    case 2:{
      Display_Students();  //Function to Display Students
      break;
    }

    case 3:{
      Search_Student();    //Function to Search for a Student
      break;
    }

    case 4:{
      Update_Marks();     //Function to update a student's marks
      break;
    }

    case 5:{
      Delete_Student();    //Function to delete any student
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

void New_Student(void){
  Student S1;
  FILE *Std;
  Std = fopen("Student_Details.txt", "a");
  if(Std == NULL){
    fprintf(stderr, "File Execution unsuccessfull!\n");
    return;
  }
  else{
  printf("New Student: \n");
  printf("Enter his name: ");
  scanf("%s", S1.name);
  printf("Enter his surname: ");
  scanf("%s", S1.SurName);
  printf("Enter his age: ");
  scanf("%d", &S1.Age);
  printf("Enter his Roll No: ");
  scanf("%d", &S1.Roll_No);
  for(int i = 0; i < 5; i++){
    printf("Enter his marks in Subject%d: ", i + 1);
    scanf("%d", &S1.Marks[i]);
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

void Display_Students(){
  printf("Student Details: \n");
  FILE *Std;
  Student S1;
  Std = fopen("Student_Details.txt", "r");
  if(Std == NULL){
    fprintf(stderr, "File Open Error!!!\n");
  }
  else{
    while(feof(Std) == 0){
      if(fread(&S1, sizeof(Student), 1, Std) > 0){
        printf("Name: %s %s\nAge: %d\nRoll No: %d\n", S1.name, S1.SurName, S1.Age, S1.Roll_No);
        for(int i = 0; i < 5; i++){
          printf("Marks in Subject %d: %d\n", i + 1, S1.Marks[i]);
        }
      }
    }
  }
  fclose(Std);
}

void Search_Student(void){
  printf("Student Search by Roll No: ");
}

void Update_Marks(void){
  printf("Update Student Marks here: ");
}

void Delete_Student(void){
  printf("Delete Students info here: ");
}