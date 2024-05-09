#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int DiceRoll(void)
{
    return (rand() % 6) + 1;
}

int main()
{
    int initBal, rndNum, dice1, dice2, sumOf2, betOn,specNUM;
    time_t t;
    srand(time(&t));
    printf("Enter the Balance you want to start with: ");
    scanf("%d",&initBal);
    printf("How many rounds you wanna play: ");
    scanf("%d",&rndNum);
    for (int i = 1; i <= rndNum; i++)
    {
        printf("\n\nIn which you wanna bet on: \n1. ODD number.\n2.EVEN number.\n3.Specific Number.\n-->");
        scanf("%d",&betOn);
        printf("You've selected strategy %d\n", betOn);
        if (betOn == 3 )
        {
            printf("Enter the number you want to bet on:");
            scanf("%d",&specNUM);
        }
        printf("Rolling Dice...\n");
        sleep(2);
        dice1 = DiceRoll();
        dice2 = DiceRoll();
        sumOf2 = dice1 + dice2;
        printf("\nYou rolled %d + %d = %d\n", dice1, dice2, sumOf2);
        switch (betOn)
        {
        case 1:
            if (sumOf2 % 2 != 0)    
            {
                printf("You've Won");
                initBal += 5;
            }
            if (sumOf2 % 2 == 0)    
            {
                printf("You've Lost");
                initBal -= 5;
            }
            break;
        case 2:
            if (sumOf2 % 2 == 0)    
            {
                printf("You've Won");
                initBal += 5;
            }
            if (sumOf2 % 2 != 0)    
            {
                printf("You've Lost");
                initBal -= 5;
            }
            break;
        case 3:
            if (sumOf2 == specNUM)    
            {
                printf("You've Won");
                initBal += 5;
            }
            else                    
            {
                printf("You've Lost");
                initBal -= 5;
            }
            break;
        default:
            printf("Invalid Input");
            break;
        }
        printf("\nYour current balance is: %d",initBal);
    }
}