#include <stdio.h>

int sum(int num)
{
    if (num == 0)
    {
        return 0;
    }
    if (num == 1)
        return 1;
    else
        return sum(num - 1);
}
int main()
{
    int number;
    printf("Enter the number up to which you want to sum:");
    scanf("%d", number);
    if (number < 0)
    {
        printf("enter positive number");
        return 0;
    }

    printf("");

    return 0;
}