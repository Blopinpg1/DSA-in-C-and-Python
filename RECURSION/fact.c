#include <stdio.h>
int fact(int number);

int main() 
{
    int number;
    printf("Enter the number: ");
    scanf("%d", &number); // Use & to get the address

    int result = fact(number);
    printf("Factorial of %d is %d\n", number, result);

    return 0;
  

}

int fact( int number)
    {
        if (number==0 || number==1)
        {
            return 1;
         }

         else
         return number*fact(number-1);
        
        

    };