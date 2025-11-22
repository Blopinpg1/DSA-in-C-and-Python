#include <stdio.h>
 int fact(int num,int a);

int main()
{
     int num;
     int a = 1; 
    printf("Enter the number: ");
    scanf("%d", &num); 

    int result = fact(num,a);
    printf("Factorial of %d is %d\n", num, result);

    return 0;
}

int fact(int n, int a)
{
    
    if (n==0)
    {
        return a;
    }
    else
    return  fact(n-1,a*n);
    
}
