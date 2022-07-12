20170401,16:39:27,Shorts M,1,120.50

#include <stdio.h>
#include <string.h>

typedef struct _product {
    char name[30];
    int amount;
    double totalCost;
} Product;

void printStock(Product stock[], int nStock)
{
    int i;
    printf("%-20s|%6s|%-10s\n", "    Product Name", "Amount", "     Total");
    for (i = 0; i < nStock; i++) {
        printf("%-20s|%6d|%10.2lf\n",
            stock[i].name, stock[i].amount, stock[i].totalCost);
    }
}

void reportStock(char *filename)
{
    FILE *file;
    int kind = 0;
    char date_buf[8];
    char time_buf[8];
    char name_buf[20];
    int amt_buf = 0;
    double cst_buf = 0;
    int last = 0;
    int name_cnt = 0;
    int done = 0;
    
    file = fopen(filename, "r");
    fscanf(file, "%d\n", &name_cnt);

    Product stock[name_cnt];

    while (fscanf(file, "%[^,],%[^,],%[^,],%d,%lf\n", date_buf, time_buf, name_buf, &amt_buf, &cst_buf) != EOF)
    {
        done = 0;
        for (int i = 0; i < name_cnt; i++)
        {
            if (!strcmp(stock[i].name, name_buf))
            {
                stock[i].amount += amt_buf;
                stock[i].totalCost += cst_buf;
                done = 1;
                break;
            }
        }
        if (!done)
        {
            strcpy(stock[last].name, name_buf);
            stock[last].amount = amt_buf;
            stock[last].totalCost = cst_buf;
            last++;
        }
    }

    fclose(file);
    printStock(stock, name_cnt);
}

int main()
{
    char filename[20];
    double average;
    scanf("%s", filename);
    reportStock(filename);
}