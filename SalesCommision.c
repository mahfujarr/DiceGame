#include<stdio.h>
int main()
{
    int salesAmount[5], commissionRate[5];
    int totalCommission[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter sales amount of Employee ID %03d: ",i+1);
        scanf("%d",&salesAmount[i]);
        printf("Enter commission percentage of Employee ID %03d: ",i+1);
        scanf("%d",&commissionRate[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        totalCommission[i] =
        (salesAmount[i]*commissionRate[i]/100);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\n\tTotal sales commission of employee ID: %03d is: %d\n",i+1,totalCommission[i]);
    }
}
