#include "Core.h"

char command[10] = " ";
char command1[10] = "Start";
char command2[10] = "Score";
char command3[10] = "Exit";
void menu(int choiceOption){
   printf("-----------------\n");
   printf("|[1] Start      |\n");
   printf("|[2] Score      |\n");
   printf("|[3] Exit       |\n");
   printf("-----------------\n");
   
   if(choiceOption==1){
     strcpy(command,command1);
     
   }
   else if (choiceOption==2)    
   {
     strcpy(command,command2);
   }
   else if(choiceOption==3){
    strcpy(command,command3);
   }
   else{
    strcpy(command," ");
   }
   
   printf("Your choice:%s",command);
}

void run(){
    int x=0;
    int *px=&x;
    menu(x);
    while (1)
    {
        if(key==upKey){
            addPointer(px,3);
            menu(x);
        }
        else if (key==downKey)
        {
            subPointer(px,3);
            menu(x);
        }
        else if (key==enterKey && x== 1)
        {
            startMenu();
        }
        else if (key==enterKey && x==2)
        {
            scoreMenu();
        }
        else if(key== enterKey && x==3){
            exit(0);
        }
      
        
        
        key=getch();
        system("cls");


    }
    
}