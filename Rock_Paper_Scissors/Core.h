#include "asset.h"
struct Player
{
    int health;
    int score;
    int shieldItem;
    int bonusDameItem;
} Player1;
void playTurn();
bool checkScore();
int healBot = 10;
char option[10] = "";
char option1[10] = "Rock";
char option2[10] = "Paper";
char option3[10] = "Scissors";
char item[10] = "";
char itemA[10] = "Bonus dame";
char itemS[10] = "Shield ";
int playerChoice = 0;
int botChoice = 0;
int itemChoice = 0;
int upKey = 72;
int downKey = 80;
int enterKey = 13;
int escKey = 27;
int leftKey = 75;
int rightKey = 77;
char key;
char key1;
char key2;
int useAI = 0;
int useSI = 0;
int turn = 1;
char *filePath = "Score.txt";
FILE *file;
char namePlayer[10] = "hnp12";
int stt;
void addPointer(int *pointer, int range)
{
    if (*pointer == range)
    {
        *pointer = 1;
    }
    else
    {
        *pointer += 1;
    }
}
void subPointer(int *pointer, int range)
{
    if (*pointer == 1)
    {
        *pointer = range;
    }
    else
    {
        *pointer -= 1;
    }
}
int randomOneNumber(int min, int max)
{

    int num = (rand() % (max - min + 1)) + min;
    srand(time(0));
    return num;
}
void choiceOption(int AItem, int SItem, int choiceOption)
{
    printf("---Turn %d---\n", turn);
    printf("Your name : %s\n", namePlayer);e43w
    printf("Your heal :%d\n", Player1.health);
    printf("Your have %d attack item and %d shield item\n", AItem, SItem);
    printf("Your choise:%s\n", option);
    printf("Choice item your want use :%s\n", item);

    if (choiceOption == 1)
    {
        strcpy(option, option1);
        strcpy(item, itemA);
        itemChoice = 1;
        playerChoice = 1;
    }
    else if (choiceOption == 2)
    {
        strcpy(option, option1);
        strcpy(item, itemS);
        itemChoice = 2;
        playerChoice = 1;
    }
    else if (choiceOption == 3)
    {
        strcpy(option, option2);
        strcpy(item, itemA);
        itemChoice = 1;
        playerChoice = 2;
    }
    else if (choiceOption == 4)
    {
        strcpy(option, option2);
        strcpy(item, itemS);
        itemChoice = 2;
        playerChoice = 2;
    }
    else if (choiceOption == 5)
    {
        strcpy(option, option3);
        strcpy(item, itemA);
        itemChoice = 1;
        playerChoice = 3;
    }
    else if (choiceOption == 6)
    {
        strcpy(option, option3);
        strcpy(item, itemS);
        itemChoice = 2;
        playerChoice = 3;
    }
}

void updatePlayer(int heal)
{
    Player1.health -= heal;
}
void updateBot()
{
    int number = randomOneNumber(4, 6);
    botChoice = number;
    showAsset(number);
}
int player1Win(int choice1, int choice2)
{
    if (choice1 == 1 && choice2 == 4)
    {
        return 0;
    }
    else if (choice1 == 1 && choice2 == 5)
    {
        return -1;
    }
    else if (choice1 == 1 && choice2 == 6)
    {
        return 1;
    }
    else if (choice1 == 2 && choice2 == 4)
    {
        return 1;
    }
    else if (choice1 == 2 && choice2 == 5)
    {
        return 0;
    }
    else if (choice1 == 2 && choice2 == 6)
    {
        return -1;
    }
    else if (choice1 == 3 && choice2 == 4)
    {
        return -1;
    }
    else if (choice1 == 3 && choice2 == 5)
    {
        return 1;
    }
    else if (choice1 == 3 && choice2 == 6)
    {
        return 0;
    }
    else
    {
        return 10;
    }
}
void result(int item)
{
    turn++;
    if (item == 2)
    {

        Player1.bonusDameItem -= 1;
        if (Player1.bonusDameItem < 0)
        {
            printf("You don't have bonus dame Item\n");
            Player1.bonusDameItem = 0;
            useAI = 0;
            useSI = 0;
        }
        else
        {
            useAI = 1;
            useSI = 0;
        }
    }
    else if (item == 1)
    {
        Player1.shieldItem -= 1;
        if (Player1.shieldItem <= 0)
        {
            printf("You don't have shield Item\n");
            Player1.shieldItem = 0;
            useSI = 0;
            useAI = 0;
        }

        else
        {
            useSI = 1;
            useAI = 0;
        }
    }
    if (player1Win(playerChoice, botChoice) == 1)
    {
        if (useAI == 1)
        {
            updatePlayer(0);
            healBot -= 2;
        }
        else if (useAI == 0)
        {
            updatePlayer(0);
            healBot -= 1;
        }
        printf("\nWin");
    }
    else if (player1Win(playerChoice, botChoice) == 0)
    {
        updatePlayer(0);
        printf("\nDraw");
    }
    else if (player1Win(playerChoice, botChoice) == -1)
    {
        if (useSI == 1)
        {
            updatePlayer(0);
        }
        else if (useSI == 0)
        {
            updatePlayer(1);
        }
        printf("\nLose");
    }
}

void WriteScore()
{
    FILE *file = fopen(filePath, "w+");
    if (file == NULL)
    {
        printf("ERROR! Cannot open file\n");
    }
    else
    {
        fprintf(file, "Best core is %s with turn:%d", namePlayer, turn);
    }

    fclose(file);
}
bool checkScore()
{
    char ch;
    int score;
    int n1 = 0;
    int n2 = 0;
    char *ptr;
    int n = 0;
    char buf[10];
    file = fopen(filePath, "a+");
    if (file == NULL)
    {
        printf("ERROR! cannot save!\n");
    }
    else
    {
        while ((ch = fgetc(file)) != EOF)
        {
            if ((int)ch == ':')
            {
            }
            else
            {
                n++;
            }
            if (n == 29)
            {
                n1 = strtol(&ch, &ptr, 10);
                score = n1;
            }
            else if (n == 30)
            {

                n2 = strtol(&ch, &ptr, 10);
                score = n1 * 10 + n2;
            }
        }
        if (turn < score)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    fclose(file);
}
void playTurn()
{

    int xx = 0;
    int *pxx = &xx;
    while (1)
    {

        if (key1 == rightKey)
        {
            addPointer(pxx, 6);
            choiceOption(Player1.bonusDameItem, Player1.shieldItem, xx);
        }
        else if (key1 == leftKey)
        {
            subPointer(pxx, 6);
            choiceOption(Player1.bonusDameItem, Player1.shieldItem, xx);
        }

        else if (key1 == enterKey)
        {

            if (playerChoice == 1)
            {
                showAsset(1);
            }
            else if (playerChoice == 2)
            {
                showAsset(2);
            }
            else if (playerChoice == 3)
            {
                showAsset(3);
            }
            updateBot();
            result(itemChoice);
            if (healBot == 0)
            {
                if (checkScore() == true)
                {
                    WriteScore();
                }
                system("cls");
                printf("You win the bot!\n");
                exit(0);
            }
            else if (Player1.health == 0)
            {
                system("cls");
                printf("You lose the bot!\n");
                exit(0);
            }
        }

        key1 = getch();
        system("cls");
    }
}
void enterName()
{
    int passName = 0;
    do
    {
        printf("Enter your name:");
        scanf("%s", &namePlayer);
        if (strlen(namePlayer) == 5)
        {
            passName = 1;
        }
        else
        {
            printf("ERROR! Name must 5 character\n");
            passName = 0;
        }
    } while (passName == 0);
    fflush(stdin);
}
void startMenu()
{
    Player1.health = 5;
    Player1.bonusDameItem = 5;
    Player1.shieldItem = 5;
    enterName();
    playTurn();
}
void scoreMenu()
{
    char ch;
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    file = fopen(filePath, "r");
    if (file == NULL)
    {
        printf("The file is not opened!\n");
    }
    else
    {

        while (fgets(buffer, MAX_LENGTH, file))
            printf("%s", buffer);
        fclose(file);
    }
}
