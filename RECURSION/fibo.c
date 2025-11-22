#include <stdio.h>
#define MAX 100
long int table[MAX];

int fibo(int n)
{

    if (n == 1 || n == 2)
        return 1;
    else
    {
        if (table[n] == 0)
        {
            table[n] = fibo(n - 1) + fibo(n - 2);
            printf("FIBONACHI number for %d is %ld\n", n, table[n]);
        }
    }
    return table[n];
}
int main()
{
    int n;

    printf("Enter number:");
    scanf("%d", &n);
    printf("FIBONACHI number is :%d", fibo(n));
}