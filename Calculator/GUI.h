#include "Core.h"
int x = 1;
int *px = &x;

int upKey = 72;
int downKey = 80;
int enterKey = 13;
int escKey = 27;
int leftKey = 75;
int rightKey = 77;
char key;
char command[10] = " ";
char command1[10] = "Start";
char command2[10] = "History";
char command3[10] = "EXIT";

void GUI(int choiceOption)
{

  printf("====================\n");
  printf("|| [1] Start      ||\n");
  printf("|| [2] History    ||\n");
  printf("|| [3] EXIT       ||\n");
  printf("====================\n");

  if (choiceOption == 1)
  {
    strcpy(command, command1);
    printf("Your command:%s", command);
  }
  else if (choiceOption == 2)
  {
    strcpy(command, command2);
    printf("Your command:%s", command);
  }
  else if (choiceOption == 3)
  {
    strcpy(command, command3);
    printf("Your command:%s", command);
  }
}
void addPointer(int *pointer)
{
  if (*pointer == 3)
  {
    *pointer = 1;
  }
  else
  {
    *pointer += 1;
  }
}
void subPointer(int *pointer)
{
  if (*pointer == 1)
  {
    *pointer = 3;
  }
  else
  {
    *pointer -= 1;
  }
}
void UI()
{
  GUI(x);
  while (1)
  {

    if (key == upKey)
    {
      subPointer(px);
      GUI(x);
    }
    else if (key == downKey)
    {
      addPointer(px);
      GUI(x);
    }
    if (key == enterKey && x == 1)
    {
      Start();
    }
    else if (key == enterKey && x == 2)
    {
      History();
    }
    else if (key == enterKey && x == 3)
    {
      exit(0);
    }
    key = getch();
    system("cls");
  }
}