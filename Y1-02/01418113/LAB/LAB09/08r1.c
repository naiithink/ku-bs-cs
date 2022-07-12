#include <stdio.h>
#include <string.h>

typedef struct _product
{
    char name[30];
    int amount;
    double totalCost;
} Product;

void printStock(Product stock[], int nStock)
{
    int i;
    printf("%-20s|%6s|%-10s\n", "    Product Name", "Amount", "     Total");
    for (i = 0; i < nStock; i++)
    {
        printf("%-20s|%6d|%10.2lf\n",
               stock[i].name, stock[i].amount, stock[i].totalCost);
    }
}

void reportStock(char *filename)
{
    FILE *fp = fopen(filename, "r");
    int count, index4, find = 0, lastword = 0;
    char index1[30], index2[30], index3[30];
    double average;
    fscanf(fp, "%d", &count);
    Product stock[count];

    for (int i = 0;; i++)
    {
        if (fscanf(fp, "%[^,],%[^,],%[^,],%d,%lf\n", index1, index2, index3, &index4, &average) == EOF)
        {
            break;
        }
        else
        {
            for (find = 0; find <= lastword; find++)
            {
                if (find == lastword)
                {
                    strcpy(stock[lastword].name, index3);
                    stock[lastword].amount = index4;
                    stock[lastword].totalCost = average;
                    lastword++;
                    break;
                }
                else if (strcmp(stock[find].name, index3) == 0)
                {
                    stock[find].amount += index4;
                    stock[find].totalCost += average;
                    break;
                }
            }
        }
    }
    fclose(fp);
    printStock(stock, count);
}

int main()
{
    char filename[20];
    double average;
    scanf("%s", filename);
    reportStock(filename);
}