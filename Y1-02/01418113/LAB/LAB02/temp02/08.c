#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to My Pizza Shop!!\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    char area_str[5], pepperoni_str[5], cheese_str[5], mushroom_str[5] ;                                           /// พวกนี้คืออะไรก็ไม่รู้วววว ;-;

        printf("Enter pizza size (1=s, 2=m, or 3=l): ");
        fgets(area_str, 5, stdin);
        printf("Extra pepperoni? (1=yes, 0=no): ");
        fgets(pepperoni_str, 5, stdin);
        printf("Extra cheese? (1=yes, 0=no): ");
        fgets(cheese_str, 5, stdin);
        printf("Extra mushroom? (1=yes, 0=no): ");
        fgets(mushroom_str, 5, stdin);

        int area = atoi(area_str);
        int pepperoni = atoi(pepperoni_str);
        int cheese = atoi(cheese_str);
        int mushroom = atoi(mushroom_str);
        int fixedcost = 5;
        int basecost = 2;
        int extracost = 0;
        float Cost = fixedcost + (basecost * area) + (extracost);
        float Price = 0;                                                                                            /// จะจำหนดอะไรเยอะแยะ!?
        
        if (area == 1 || area == 2 || area == 3)                                                                    /// สิ่งที่คุณจะพบเจอต่อไปนี้คือหายนะ
        {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            if ( area == 1 && pepperoni == 0 && cheese == 0 && mushroom == 0 )                                      /// SMALL SIZE
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(10.0,2.0)/4.0)) + (0 * (M_PI * pow(10.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 1 && pepperoni == 1 && cheese == 0 && mushroom == 0 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(10.0,2.0)/4.0)) + (0.5 * (M_PI * pow(10.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 1 && pepperoni == 1 && cheese == 1 && mushroom == 0 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(10.0,2.0)/4.0)) + (0.75 * (M_PI * pow(10.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 1 && pepperoni == 1 && cheese == 1 && mushroom == 1 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(10.0,2.0)/4.0)) + (1.05 * (M_PI * pow(10.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 1 && pepperoni == 0 && cheese == 1 && mushroom == 0 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(10.0,2.0)/4.0)) + (0.25 * (M_PI * pow(10.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 1 && pepperoni == 0 && cheese == 0 && mushroom == 1 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(10.0,2.0)/4.0)) + (0.30 * (M_PI * pow(10.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 1 && pepperoni == 0 && cheese == 1 && mushroom == 1 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(10.0,2.0)/4.0)) + (0.55 * (M_PI * pow(10.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 1 && pepperoni == 1 && cheese == 0 && mushroom == 1 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(10.0,2.0)/4.0)) + (0.8 * (M_PI * pow(10.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 2 && pepperoni == 0 && cheese == 0 && mushroom == 0 )                                     /// MEDIUM SIZE
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(16.0,2.0)/4.0)) + (0 * (M_PI * pow(16.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 2 && pepperoni == 1 && cheese == 0 && mushroom == 0 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(16.0,2.0)/4.0)) + (0.5 * (M_PI * pow(16.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 2 && pepperoni == 1 && cheese == 1 && mushroom == 0 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(16.0,2.0)/4.0)) + (0.75 * (M_PI * pow(16.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 2 && pepperoni == 1 && cheese == 1 && mushroom == 1 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(16.0,2.0)/4.0)) + (1.05 * (M_PI * pow(16.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 2 && pepperoni == 0 && cheese == 1 && mushroom == 0 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(16.0,2.0)/4.0)) + (0.25 * (M_PI * pow(16.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 2 && pepperoni == 0 && cheese == 0 && mushroom == 1 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(16.0,2.0)/4.0)) + (0.30 * (M_PI * pow(16.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 2 && pepperoni == 0 && cheese == 1 && mushroom == 1 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(16.0,2.0)/4.0)) + (0.55 * (M_PI * pow(16.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 2 && pepperoni == 1 && cheese == 0 && mushroom == 1 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(16.0,2.0)/4.0)) + (0.8 * (M_PI * pow(16.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            if ( area == 3 && pepperoni == 0 && cheese == 0 && mushroom == 0 )                                      /// LARGE SIZE
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(20.0,2.0)/4.0)) + (0 * (M_PI * pow(20.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 3 && pepperoni == 1 && cheese == 0 && mushroom == 0 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(20.0,2.0)/4.0)) + (0.5 * (M_PI * pow(20.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 3 && pepperoni == 1 && cheese == 1 && mushroom == 0 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(20.0,2.0)/4.0)) + (0.75 * (M_PI * pow(20.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 3 && pepperoni == 1 && cheese == 1 && mushroom == 1 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(20.0,2.0)/4.0)) + (1.05 * (M_PI * pow(20.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 3 && pepperoni == 0 && cheese == 1 && mushroom == 0 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(20.0,2.0)/4.0)) + (0.25 * (M_PI * pow(20.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 3 && pepperoni == 0 && cheese == 0 && mushroom == 1 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(20.0,2.0)/4.0)) + (0.30 * (M_PI * pow(20.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 3 && pepperoni == 0 && cheese == 1 && mushroom == 1 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(20.0,2.0)/4.0)) + (0.55 * (M_PI * pow(20.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
            else if ( area == 3 && pepperoni == 1 && cheese == 0 && mushroom == 1 )
            {
                Cost = 5.0 + (2.0 * (M_PI * pow(20.0,2.0)/4.0)) + (0.8 * (M_PI * pow(20.0,2.0)/4.0));
                Price = Cost * 1.5;
                printf("Your order costs %.02f baht.\n",Price);
                printf("Thank you.");
            }
        }
}