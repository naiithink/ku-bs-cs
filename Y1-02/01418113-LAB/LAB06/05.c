#include <stdio.h>
#define BOARD_SIZE 8

void bishopMoves(int board[][BOARD_SIZE], int x, int y) {
    char bishop = 'B';
    char bishop_move = 'X';
    int b1 = y - x;
    int b2 = y + x;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (i == (j+b1) || i == (-j+b2))
                board[i][j] = bishop_move;
            else
                board[i][j] = 32;
        }
    }
    board[y][x] = bishop;
}

int main() {
    int x = -1, y = -1;
    int board[BOARD_SIZE][BOARD_SIZE];

    printf("Enter Bishop's X Y position: ");
    scanf("%d %d", &x, &y);

    bishopMoves(board, x, y);

    for (int i = 0; i <= (BOARD_SIZE*2)+1; i++)
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
                {
                    if (i%2)
                        printf("%c", 45);
                    else
                        printf("%d", (i - 2) / 2);
                }
            }
            else if (i%2)
                printf("%c", 45);
            else if (j%2)
                printf("%c", 124);
            else
                printf("%c", board[((i-2)/2)][((j-2)/2)]);
        }
        printf("\n");
    }

    return 0;
}