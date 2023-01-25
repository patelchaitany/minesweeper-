#include <bits/stdc++.h>
using namespace std;

#define BEGINNER 0
#define INTERMEDIATE 1
#define ADVANCED 2
#define MAXSIDE 25
#define MAXMINES 99
#define MOVESIZE 526 // (25 * 25 - 99)

int SIDE;  
int MINES; 

bool isValid(int r, int c)
{
   
    return (r >= 0) && (r < SIDE) &&
           (c >= 0) && (c < SIDE);
}


bool isMine(int r, int c, char board[][MAXSIDE])
{
    if (board[r][c] == '*')
        return (true);
    else
        return (false);
}


void makeMove(int *x, int *y)
{
   
    printf("Enter your move, (r, column) -> ");
    scanf("%d %d", x, y);
    return;
}

void printBoard(char B1[][MAXSIDE])
{
    int i, j;

    printf("    ");

    for (i = 0; i < SIDE; i++)
        printf("%d ", i);

    printf("\n\n");

    for (i = 0; i < SIDE; i++)
    {
        printf("%d   ", i);

        for (j = 0; j < SIDE; j++)
            printf("%c ", B1[i][j]);
        printf("\n");
    }
    return;
}


int countAdjacentMines(int r, int c, int M[][2],
                       char B2[][MAXSIDE])
{

    int i;
    int count = 0;

  
    if (isValid(r - 1, c) == true)
    {
        if (isMine(r - 1, c, B2) == true)
            count++;
    }

    if (isValid(r + 1, c) == true)
    {
        if (isMine(r + 1, c, B2) == true)
            count++;
    }

    if (isValid(r, c + 1) == true)
    {
        if (isMine(r, c + 1, B2) == true)
            count++;
    }

    if (isValid(r, c - 1) == true)
    {
        if (isMine(r, c - 1, B2) == true)
            count++;
    }

    if (isValid(r - 1, c + 1) == true)
    {
        if (isMine(r - 1, c + 1, B2) == true)
            count++;
    }

    if (isValid(r - 1, c - 1) == true)
    {
        if (isMine(r - 1, c - 1, B2) == true)
            count++;
    }

    if (isValid(r + 1, c + 1) == true)
    {
        if (isMine(r + 1, c + 1, B2) == true)
            count++;
    }

    if (isValid(r + 1, c - 1) == true)
    {
        if (isMine(r + 1, c - 1, B2) == true)
            count++;
    }

    return (count);
}


bool playM(char B1[][MAXSIDE], char B2[][MAXSIDE],
                         int M[][2], int r, int c, int *movesLeft)
{


    if (B1[r][c] != '-')
        return (false);

    int i, j;

    
    if (B2[r][c] == '*')
    {
        B1[r][c] = '*';

        for (i = 0; i < MINES; i++)
            B1[M[i][0]][M[i][1]] = '*';

        printBoard(B1);
        printf("\nYou lost!\n");
        return (true);
    }

    else
    {
       
        int count = countAdjacentMines(r, c, M, B2);
        (*movesLeft)--;

        B1[r][c] = count + '0';

        if (!count)
        {
          
            if (isValid(r - 1, c) == true)
            {
                if (isMine(r - 1, c, B2) == false)
                    playM(B1, B2, M, r - 1, c, movesLeft);
            }

           
            if (isValid(r + 1, c) == true)
            {
                if (isMine(r + 1, c, B2) == false)
                    playM(B1, B2, M, r + 1, c, movesLeft);
            }


            if (isValid(r, c + 1) == true)
            {
                if (isMine(r, c + 1, B2) == false)
                    playM(B1, B2, M, r, c + 1, movesLeft);
            }

           
            if (isValid(r, c - 1) == true)
            {
                if (isMine(r, c - 1, B2) == false)
                    playM(B1, B2, M, r, c - 1, movesLeft);
            }

           
            if (isValid(r - 1, c + 1) == true)
            {
                if (isMine(r - 1, c + 1, B2) == false)
                    playM(B1, B2, M, r - 1, c + 1, movesLeft);
            }

            if (isValid(r - 1, c - 1) == true)
            {
                if (isMine(r - 1, c - 1, B2) == false)
                    playM(B1, B2, M, r - 1, c - 1, movesLeft);
            }


            if (isValid(r + 1, c + 1) == true)
            {
                if (isMine(r + 1, c + 1, B2) == false)
                    playM(B1, B2, M, r + 1, c + 1, movesLeft);
            }


            if (isValid(r + 1, c - 1) == true)
            {
                if (isMine(r + 1, c - 1, B2) == false)
                    playM(B1, B2, M, r + 1, c - 1, movesLeft);
            }
        }

        return (false);
    }
}


void placeMines(int M[][2], char B2[][MAXSIDE])
{
    bool mark[MAXSIDE * MAXSIDE];

    memset(mark, false, sizeof(mark));

    for (int i = 0; i < MINES;)
    {
        int random = rand() % (SIDE * SIDE);
        int x = random / SIDE;
        int y = random % SIDE;

        
        if (mark[random] == false)
        {
            M[i][0] = x;
            M[i][1] = y;

            B2[M[i][0]][M[i][1]] = '*';
            mark[random] = true;
            i++;
        }
    }

    return;
}


void initialise(char B2[][MAXSIDE], char B1[][MAXSIDE])
{

    srand(time(NULL));

    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            B1[i][j] = B2[i][j] = '-';
        }
    }

    return;
}


void cheatMinesweeper(char B2[][MAXSIDE])
{
    printf("The M locations are-\n");
    printBoard(B2);
    return;
}

void replaceMine(int r, int c, char board[][MAXSIDE])
{
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
       
            if (board[i][j] != '*')
            {
                board[i][j] = '*';
                board[r][c] = '-';
                return;
            }
        }
    }
    return;
}


void playMinesweeper()
{
   
    bool gameOver = false;


    char B2[MAXSIDE][MAXSIDE], B1[MAXSIDE][MAXSIDE];

    int movesLeft = SIDE * SIDE - MINES, x, y;
    int M[MAXMINES][2]; 

    initialise(B2, B1);


    placeMines(M, B2);



    int currentMoveIndex = 0;
    while (gameOver == false)
    {
        printf("Current Status of Board : \n");
        printBoard(B1);
        makeMove(&x, &y);

        if (currentMoveIndex == 0)
        {
           
            if (isMine(x, y, B2) == true)
                replaceMine(x, y, B2);
        }

        currentMoveIndex++;

        gameOver = playM(B1, B2, M, x, y, &movesLeft);

        if ((gameOver == false) && (movesLeft == 0))
        {
            printf("\nYou won !\n");
            gameOver = true;
        }
    }
    return;
}


void levelA()
{

    int level;

    printf("Enter the Difficulty Level\n");
    printf("Press 0 for BEGINNER (9 * 9 Cells and 10 Mines)\n");
    printf("Press 1 for INTERMEDIATE (16 * 16 Cells and 40 Mines)\n");
    printf("Press 2 for ADVANCED (24 * 24 Cells and 99 Mines)\n");

    scanf("%d", &level);

    if (level == BEGINNER)
    {
        SIDE = 9;
        MINES = 10;
    }

    if (level == INTERMEDIATE)
    {
        SIDE = 16;
        MINES = 40;
    }

    if (level == ADVANCED)
    {
        SIDE = 24;
        MINES = 99;
    }

    return;
}

int main()
{
 
    levelA();

    playMinesweeper();

    return (0);
}