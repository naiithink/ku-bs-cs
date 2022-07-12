#include <stdio.h>

#define BOARD_SIZE    8

void setPieceOnTable(int board[][BOARD_SIZE], char piece, int xPos, int yPos);

int main() {
    /* your code here */
    char pieceChar = '\0';
    int numPieces = 0, x = 0, y = 0;
    int board[BOARD_SIZE][BOARD_SIZE];

    scanf("%d", &numPieces);

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = 32;
    }
    
    for (int i = 0; i < numPieces; i++)
    {
        scanf("\n%c(%d, %d)", &pieceChar, &x, &y);
        setPieceOnTable(board, pieceChar, x, y);
    }

    printf("------------------\n");
    for (int i = 0; i <= BOARD_SIZE; i++)
    {
        for (int j = 0; j <= (BOARD_SIZE*2)+1; j++)
        {
            if (!i || !j)
            {
                if (!(i+j))
                    printf("%c", 32);
                else if (!i)
                {
                    if (j%2)
                        printf("%c", 32);
                    else
                        printf("%d", (j - 2) / 2);
                }
                else if (!j)
                    printf("%d", i-1);
            }
            else if (j%2)
                printf("%c", 124);
            else
                printf("%c", board[i-1][((j-2)/2)]);
        }
        printf("\n");
    }

    return 0;
}

void setPieceOnTable(int board[][BOARD_SIZE], char piece, int xPos, int yPos )
{
    /* your code here */
    board[yPos][xPos] = piece;
}