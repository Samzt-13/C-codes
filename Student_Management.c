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
    int age, rollNO;
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
  printf("1.Add New Student\n");     //ask to add a new student
  printf("2.Display Students\n");     //ask to diplay a new student
  printf("3.Search Student\n");       //ask to search a new student
  printf("4.Update Student\n");       //ask to update a new student
  printf("5.Delete Student\n");       //ask to delete a new student
  printf("6.Exit\n");                 //exit the program
  printf("Enter your choice: ");      
  if(scanf("%d", &User_Choice) == 0){
      fprintf(stderr, "Error Input Provided!!!!");      //error message if the input is not a number
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
      printf("\n\n\nExiting the program!!\n");
      printf("Thanks for using it\n");
      printf("Developed by--Samrat Parajuli\n");
      printf("\t\t\t\t\tEXIT\n");    //just some design stuff
      printf(RESET);   //reset the color to normal 
      exit(0);        //exit the loop
      break;
    }

    default:{
        fprintf(stderr, "Error!!\nIvalid Input Provided!\n");   //invalid message on unexpected message
    }
  }
}

void newStudent(void){
  system("cls");
  printf("\t\t\t:::NEW STUDENT:::");
  printf("\n\n\n");
  Student S1;     //giving name to the struct
  FILE *Std;   //declaring the file
  Std = fopen("Student_Details.txt", "a");   //opening the file in "append mode"
  if(Std == NULL){
    fprintf(stderr, "File Execution unsuccessfull!\n");  //error message
    return;
  }
  else{
  Start:          //just for the goto function
  printf("New Student: \n");
  printf("Enter his name: ");    //get student name
  scanf("%s", S1.name);
  printf("Enter his surname: ");      //get student surname
  scanf("%s", S1.surName);
  printf("Enter his age: ");        //get student age
  if(scanf("%d", &S1.age) == 0){
    fprintf(stderr, "Invalid input provided!!!\n");      //invalid message
    goto Start;       //return to "Start" for the invalid input
  }
  printf("Enter his Roll No: ");
  if(scanf("%d", &S1.rollNO) == 0){
    fprintf(stderr, "Invalid input provided!!!\n");
    goto Start;         //return to "Start" for the invalid input
  }
  printf("Enter his course name: ");
  scanf("%s", S1.course);     
  if(fwrite(&S1, sizeof(Student), 1, Std) > 0){
    printf("Data Registered Successfully!\n");    //data registered in file
  }
  else{
    fprintf(stderr, "Data Registration Error!!!\n");      //data registration error
  }
  }
  fclose(Std);        //close the file
}

void displayStudents(){
  printf("\t\t\t:::STUDENT DISPLAY:::");   //system display
  printf("\n\n\n");
  printf("\nStudent Details: \n");      //Some info message for better User Interface
  FILE *Std;
  Student S1;
  Std = fopen("Student_Details.txt", "r");   //file opening in read mode
  if(Std == NULL){
    fprintf(stderr, "File Open Error!!!\n");    //error message with "stderr" 
  }
  else{
    while(feof(Std) == 0){     //while the end of the file has been reached
      if(fread(&S1, sizeof(Student), 1, Std) > 0){   //if the data we read from the file is not symbols
        printf("\nName: %s %s\nAge: %d\nRoll No: %d\nCourse: %s\n", S1.name, S1.surName, S1.age, S1.rollNO, S1.course);    //printing details
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
  printf("Enter his name: ");
  scanf("%s", name);
  while(feof(Std) == 0){
    if(fread(&S1, sizeof(Student), 1, Std) > 0){
      if((strcmp(S1.name, name)) == 0){  //if the file is found, print it
        printf("Name: %s %s\nAge: %d\nRoll No: %d\nCourse: %s\n", S1.name, S1.surName, S1.age, S1.rollNO, S1.course);
        count++;
      }
    }
   }
   if(count < 1){
      printf("Student Not Found!!!\n");   //error message on file not found
   }
  }
  fclose(Std);      //close the file
}

void updateStudent(void){
  system("cls");
  printf("\n\n\n");
  char name[100];
  int found = 0;
  FILE *std;      //open file
  Student S1;     //declare struct
  std = fopen("Student_Details.txt", "r+");
  if(std == NULL){
    fprintf(stderr, "File execution error");   //error message on file error
  }
  printf("\nUpdate Student Details!!!\n");
  printf("Enter his name to proceed: \n");
  scanf("%s", name);    //get the student name to update
  while(feof(std) == 0){
    if(fread(&S1, sizeof(Student), 1, std) > 0){
      if((strcmp(S1.name, name)) == 0){   //if the data is found, edit it.
          printf("Enter his new detail: ");
          printf("FUll Name: ");
          scanf("%s %s", S1.name, S1.surName);        //edit student info
          printf("Enter his new Age: ");
          scanf("%d", &S1.age);
          printf("Enter his new Roll No: ");
          scanf("%d", &S1.rollNO);
          printf("Enter his new course: ");
          scanf("%s", S1.course);
          fseek(std, -sizeof(Student), SEEK_CUR);    //move the file pointer back
          fwrite(&S1, sizeof(Student), 1, std);         //overwrite the file details in std
          fflush(std);    //Ensure file changes
          found++;
        }
    }
  }
  if(!found){
    printf("Student not found\n");    //error if file is not found
  }
  else{
  printf("File Update Sucessfull");
  }
  fclose(std);   //close the file
}

void deleteStudent(void){
  system("cls");    //system function to clear screen
  printf("\n\n\n\n");    //print new lines for better UI
  char name[100];         
  int found = 0;
  FILE *std, *temp;       //file declaration
  Student S1;     //struct declaration
  std = fopen("Student_Details.txt", "r+");     //open std in "r+" to both read & write
  temp = fopen("Temp.txt", "a");          //open temp in append mode
  if(std == NULL || temp == NULL){
    fprintf(stderr, "\nFile Execution Error!!!!\n");      //show error if anyof them doesnot open
  }
  printf("\t\t\t\tDELETE STUDENT\n");
  printf("Enter student name: ");
  scanf("%s", name);      //get the student name
  while(feof(std) == 0){
    if(fread(&S1, sizeof(Student), 1, std) > 0){   //find the student
      if(strcmp(name, S1.name) == 0){  
        found++;      //if found do not do anything
      }
      else{
        fwrite(&S1, sizeof(Student), 1, temp);    //if its not that student then write it into temp
      }
    }
  }

  fclose(std);      //close both files
  fclose(temp);

  if(found){   //if the detail was found
    remove("Student_Details.txt");      //remove original
    rename("temp.txt", "Student_Details.txt");    //rename temp as "Student_Details.txt"
    printf("Student Data Deleted!!");         //print it was found
  }
  else{
    printf("Student Not Found!!!");     //if not found
    remove("Temp.txt");     //remove temp
  }
}