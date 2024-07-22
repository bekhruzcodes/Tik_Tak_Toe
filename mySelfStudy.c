#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define SIZE 3
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

int wins = 0;
int loss = 0;
int draws = 0;

char board[SIZE][SIZE] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};

char refreshBoard[SIZE][SIZE] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};

/*
Tic Tac Toe

Play with friend
Play with computer
See your scores >>> Played 10 games \n Won 3 games \n Lost 2 games \n Draw 5 games
Tough Games (4X4 / 5X5)
Manual/Guidebook
Quite the game


My AI for the game:
We will use the same if conditions to check the available options and
opponent's possible moves and choose the one that
blocks and/or wins the game.


Tough Games:
For now only playing with friend and tough games are counted seperately
only when the user wins.



Guidebook:
Text with samples.


Voice orqali buyruqlarni tanlash. Lekin ovoz yozyapti, uni filega text qilib yozyapti
va shu yerdan keyin nimadir bo'lyapti


*/

void menu();
int choose();
void showMyScores();
void refreshMyBoard();
void displayBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE], char player);
int checkDraw(char board[SIZE][SIZE]);
void makeMove(char board[SIZE][SIZE], char player);
void makeMoveAI(char board[SIZE][SIZE]);
void playWithFriend(char board[SIZE][SIZE], int currentPlayer);
void playWithComp(char board[SIZE][SIZE], int currentPlayer);
void clearScreen()
{
    printf("\033[H\033[J");
}

int main()
{
    srand(time(0));
    char currentPlayer = 'X';
    menu();

    return 0;
}








void refreshMyBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = refreshBoard[i][j];
        }
    }
}

void displayBoard(char board[SIZE][SIZE])
{
    clearScreen();
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 'X')
            {
                printf(" " RED "%c" RESET " ", board[i][j]);
            }
            else if (board[i][j] == 'O')
            {
                printf(" " GREEN "%c" RESET " ", board[i][j]);
            }
            else
            {
                printf(" %d ", i * SIZE + j + 1);
            }
            if (j < SIZE - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1)
        {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE], char player)
{

    for (int i = 0; i < SIZE; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return 1;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return 1;
    }

    return 0;
}

int checkDraw(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return 0;
            }
        }
    }
    return 1;
}

void makeMove(char board[SIZE][SIZE], char player)
{
    int move;
    while (1)
    {  
        printf("Ishtirokchi %c tanlovingizni kiriting: ", player);
        scanf("%d", &move);
        if (move > 0 && move < 10)
        {
            int row = (move - 1) / SIZE;
            int col = (move - 1) % SIZE;

            if (board[row][col] != 'X' && board[row][col] != 'O')
            {
                board[row][col] = player;
                break;
            }
            else
            {
                printf(" " RED "Bunday bo'sh katakcha yo'q. Qayta urinib ko'ring.\n" RESET " ");
            }
        }

    }
}

void makeMoveAI(char board[SIZE][SIZE])
{
    int move = 0;

    if (move == 0)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] != 'O' && board[i][2] != 'X')
            {
                board[i][2] = 'O';
                return;
            }
            else if (board[i][0] == 'O' && board[i][2] == 'O' && board[i][1] != 'O' && board[i][1] != 'X')
            {
                board[i][1] = 'O';
                return;
            }
            else if (board[i][1] == 'O' && board[i][2] == 'O' && board[i][0] != 'O' && board[i][0] != 'X')
            {
                board[i][0] = 'O';
                return;
            }

            else if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] != 'O' && board[2][i] != 'X')
            {
                board[2][i] = 'O';
                return;
            }
            else if (board[0][i] == 'O' && board[2][i] == 'O' && board[1][i] != 'O' && board[1][i] != 'X')
            {
                board[1][i] = 'O';
                return;
            }
            else if (board[1][i] == 'O' && board[2][i] == 'O' && board[0][i] != 'O' && board[0][i] != 'X')
            {
                board[0][i] = 'O';
                return;
            }
        }

        if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] != 'O' && board[2][2] != 'X')
        {
            board[2][2] = 'O';
            move = 1;
        }
        else if (board[0][0] == 'O' && board[2][2] == 'O' && board[1][1] != 'O' && board[1][1] != 'X')
        {
            board[1][1] = 'O';
            move = 1;
        }
        else if (board[2][2] == 'O' && board[1][1] == 'O' && board[0][0] != 'O' && board[0][0] != 'X')
        {
            board[0][0] = 'O';
            move = 1;
        }

        else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] != 'O' && board[2][0] != 'X')
        {
            board[2][0] = 'O';
            move = 1;
        }
        else if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] != 'O' && board[0][2] != 'X')
        {
            board[0][2] = 'O';
            move = 1;
        }
        else if (board[2][0] == 'O' && board[0][2] == 'O' && board[1][1] != 'O' && board[1][1] != 'X')
        {
            board[1][1] = 'O';
            move = 1;
        }
    }

    // DEFENDING MOVE FROM MY AI IN CASE THERE IS NO ANY WINNING MOVE

    if (move == 0)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] != 'O')
            {
                board[i][2] = 'O';
                return;
            }
            else if (board[i][0] == 'X' && board[i][2] == 'X' && board[i][1] != 'O')
            {
                board[i][1] = 'O';
                return;
            }
            else if (board[i][1] == 'X' && board[i][2] == 'X' && board[i][0] != 'O')
            {
                board[i][0] = 'O';
                return;
            }

            else if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] != 'O')
            {
                board[2][i] = 'O';
                return;
            }
            else if (board[0][i] == 'X' && board[2][i] == 'X' && board[1][i] != 'O')
            {
                board[1][i] = 'O';
                return;
            }
            else if (board[1][i] == 'X' && board[2][i] == 'X' && board[0][i] != 'O')
            {
                board[0][i] = 'O';
                return;
            }
        }

        if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] != 'O')
        {
            board[2][2] = 'O';
        }
        else if (board[0][0] == 'X' && board[2][2] == 'X' && board[1][1] != 'O')
        {
            board[1][1] = 'O';
        }
        else if (board[2][2] == 'X' && board[1][1] == 'X' && board[0][0] != 'O')
        {
            board[0][0] = 'O';
        }

        else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] != 'O')
        {
            board[2][0] = 'O';
        }
        else if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] != 'O')
        {
            board[0][2] = 'O';
        }
        else if (board[2][0] == 'X' && board[0][2] == 'X' && board[1][1] != 'O')
        {
            board[1][1] = 'O';
        }
        else
        {
            while (1)
            {
                move = rand() % 9 + 1;
                int row = (move - 1) / SIZE;
                int col = (move - 1) % SIZE;

                if (board[row][col] != 'X' && board[row][col] != 'O')
                {
                    board[row][col] = 'O';
                    break;
                }
            }
        }
    }
}

void playWithFriend(char board[SIZE][SIZE], int currentPlayer)
{
    while (1)
    {
        clearScreen();
        displayBoard(board);
        makeMove(board, currentPlayer);

        if (checkWin(board, currentPlayer))
        {
            clearScreen();
            displayBoard(board);
            printf(" " GREEN "Ishtirokchi %c g'alaba qozondi!\n" RESET " ", currentPlayer);
            if (currentPlayer == 'X')
                wins++;
            else
                loss++;
            refreshMyBoard();
            choose();
            break;
        }
        else if (checkDraw(board))
        {
            clearScreen();
            displayBoard(board);
            printf(" " GREEN "Do'stlik g'alaba qozondi!\n" RESET " ", currentPlayer);
            draws++;
            refreshMyBoard();
            choose();
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

void playWithComp(char board[SIZE][SIZE], int currentPlayer)
{
    while (1)
    {
        clearScreen();
        displayBoard(board);
        makeMove(board, currentPlayer);

        if (checkWin(board, currentPlayer))
        {
            displayBoard(board);
            printf(" " GREEN "Ishtirokchi %c g'alaba qozondi!\n" RESET " ", currentPlayer);
            wins++;
            refreshMyBoard();
            choose();
            break;
        }
        else if (checkDraw(board))
        {
            displayBoard(board);
            printf(" " GREEN "Do'stlik g'alaba qozondi!\n" RESET " ");
            draws++;
            refreshMyBoard();
            choose();
            break;
        }

        makeMoveAI(board);

        if (checkWin(board, 'O'))
        {
            displayBoard(board);
            printf(" " GREEN "Men g'alaba qozondim :)\n" RESET " ");
            loss++;
            refreshMyBoard();
            choose();
            break;
        }
        else if (checkDraw(board))
        {
            displayBoard(board);
            printf(" " GREEN "Do'stlik g'alaba qozondi!\n" RESET " ");
            draws++;
            refreshMyBoard();
            choose();
            break;
        }
    }
}

int choose()
{
    int choice = 3;
    while (choice > 2)
    {
        printf("1.Asosiy menyuga qaytish\n2.Chiqish\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            clearScreen();
            menu();
        }
        else if (choice == 2)
        {
            clearScreen();
            return 0;
        }
    }
}
void showMyScores()
{

    puts("");
    printf("Ishtirokchi X ning ko'rsatgichlari:\n");
    printf("G'alabalar soni: %d\n", wins);
    printf("Mag'lubiyatlar soni: %d\n", loss);
    printf("Durranglar soni: %d\n", draws);
    puts("");
    choose();
}

void menu()
{
    int choice;
    puts("");
    printf("1.Suniy intelekt bilan o'yin\n");
    printf("2.Do'stingiz bilan o'yin\n");
    printf("3.Natijalarni ko'rish\n");
    printf("0.Chiqish\n");
    puts("");
    printf("Tanlovingizni kiriting: ");
    scanf("%d", &choice);
    clearScreen();
    switch (choice)
    {
    case 1:
        playWithComp(board, 'X');
        break;
    case 2:
        playWithFriend(board, 'X');
        break;
    case 3:
        showMyScores();
        break;
    case 0:
        break;

    default:
        printf("Xato buyruq kiritildi!\n");
        menu();
        break;
    }
}
