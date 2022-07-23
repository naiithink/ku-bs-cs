#include <stdio.h>

#define TABLE_COLUMNS 6
#define TABLE_START_INDEX 1

int main(void)
{
    int num_table = 0, booking_table = 0;
    int i = 0, j = 0;
    int main_rows, table_check = 0;
    int input_row = 0, input_coloumn = 0;

    /* >>> */
    int stop = 0;
    int non_seated_column = 0;
    /* <<< */

    //จำนวนโต๊ะ
    scanf("%d", &num_table);
    if (num_table < 1)
    {
        printf("Error");
    }
    else if (num_table > 40)
    {
        printf("Error!");
    }
    else
    {
        //จำนวนที่นั่งที่มีการจอง
        scanf("%d", &booking_table);
        if (num_table < 0)
        {
            printf("Error");
        }
        else if (booking_table > num_table || booking_table > 40)
        {
            printf("Error!");
        }
        else
        {
            // TABLES           ROWS        LAST COLS       MOD
            // 6 ->             1           6               6 % 6   == 0
            // 7 ->             2           1               7 % 6   == 1
            // 8 ->             2           2               8 % 6   == 2

            main_rows = num_table / 6;
            if ((non_seated_column = num_table % 6) > 0)
                main_rows++;

            /* >>> */
            char tables[main_rows][TABLE_COLUMNS];
            /* <<< */

            for (i = 0, stop = 0; !stop && i < main_rows; i++)
            {
                // if (non_seated_column > 0
                //     && table_check == num_table)
                // {
                //     break;
                // }
                for (j = 0; !stop && j < TABLE_COLUMNS; j++)
                {
                    if (non_seated_column > 0
                        && i == (main_rows - TABLE_START_INDEX)
                        && j == non_seated_column)
                    {
                        stop = 1;
                        break;
                    }
                    tables[i][j] = 'X';
                }
            }

            // calculate booking table
            //  'X' = Not Booking 'S' = Booking
            while (table_check < booking_table)
            {
                scanf("%d %d", &input_row, &input_coloumn);

                if (input_row < TABLE_START_INDEX || input_row > main_rows
                    || input_coloumn < TABLE_START_INDEX || input_coloumn > TABLE_COLUMNS
                    || (input_row == main_rows && input_coloumn > non_seated_column)
                    || (tables[input_row - TABLE_START_INDEX][input_coloumn - TABLE_START_INDEX] != 'X' && tables[input_row - TABLE_START_INDEX][input_coloumn - TABLE_START_INDEX] != 'S'))
                {
                    printf("%d %d Out of range!\n", input_row, input_coloumn);
                    continue;
                }

                if (tables[input_row - TABLE_START_INDEX][input_coloumn - TABLE_START_INDEX] == 'S')
                {
                    continue;
                }
                else
                {
                    tables[input_row - TABLE_START_INDEX][input_coloumn - TABLE_START_INDEX] = 'S';
                    table_check++;
                }
            }

            // check table and print
            for (input_row = 0, stop = 0; !stop && input_row < main_rows; input_row++)
            {
                for (input_coloumn = 0; !stop && input_coloumn < TABLE_COLUMNS; input_coloumn++)
                {
                    if (non_seated_column > 0
                        && input_row == (main_rows - TABLE_START_INDEX)
                        && input_coloumn == non_seated_column)
                    {
                        stop = 1;
                        break;
                    }
                    printf("%c ", tables[input_row][input_coloumn]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
