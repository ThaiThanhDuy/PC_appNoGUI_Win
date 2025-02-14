/*Library*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
/*Variable global*/
int choiceMenu = 0;
bool haveChoice = false;
char nameStudent[40];
char line[256]; // Buffer for each line (adjust size if needed)
int number;
char *token;
char numberStudent[5];
struct student
{
    int number;
    char firstName[10];
    char lastName[10];
}Student;
void checkNumber();

/*Funtion*/
void GUI();
void addStudent();
void main()
{
    GUI();
}
void GUI()
{

    printf("===========MENU===========\n");
    printf("||[1] Add new student   ||\n");
    printf("||[2] Show all student  ||\n");
    printf("||[3] Search student    ||\n");
    printf("||[4] Edit student      ||\n");
    printf("||[5] Delete student    ||\n");
    printf("||[6] Delete all student||\n");
    printf("||[7] Exit              ||\n");
    printf("==========================\n");
    do
    {
        printf("Enter the choice:");
        scanf("%d", &choiceMenu);
        if (choiceMenu == 1)
        {
            addStudent();

        }
        else if (choiceMenu == 7)
        {
            exit(0);
            haveChoice = true;
        }
        else
        {
            system("cls");
            GUI();
            haveChoice = false;
        }

    } while (haveChoice == false);
}

void addStudent(){
    FILE* filePath;
    filePath = fopen("db.txt","a+");
    if(filePath==NULL){
        printf("Error open file\n");
        choiceMenu = 0;
    }
    else{
        haveChoice = true;
   
        while (fgets(line, sizeof(line), filePath) != NULL) {
            token = strtok(line, " "); 
            if (token != NULL) { 

                if (sscanf(token, "%d", &number) == 1) { 
                   
                } 
                else{
                    number =0;
                    break;
                }
            } else {
                printf("Warning: Empty line encountered.\n");
            }
        }
    
        printf("Number: %d\n", number+1);
        
        Student.number = number + 1;
        sprintf(numberStudent,"%d",Student.number);

        printf("Enter first name:");
        scanf("%s",&Student.firstName);
        printf("Enter last name:");
        scanf("%s",&Student.lastName);

        strcat(nameStudent,numberStudent);                              
        strcat(nameStudent," ");
        strcat(nameStudent,Student.firstName);
        strcat(nameStudent," ");
        strcat(nameStudent,Student.lastName);
        printf("%s",nameStudent);

        fprintf(filePath,nameStudent);
        //fprintf(filePath,"\n");
        fclose(filePath);
    }
   
}

