#include <stdio.h>
#define MAX 5 // Size of stack defined

struct STACK
{
    int TOS;      // Top of the stack variable
    int arr[MAX]; // this is my stack as array

} S = {-1};

// Function declaration or prototype
void PUSH(int a);
int POP();
int ISFULL();
int ISEMPTY();

int main()
{
    int element, input; // input is for choosing  and element is for the element in the stack
    while (1)
    {
        printf("\n\nChoose what you want to do:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. ISFULL CHECK\n");
        printf("4. ISEMPTY CHECK\n");
        printf("5. Exit\n");
        scanf("%d", &input);

        switch (input)
        {
        case 1:

            printf("\nEnter the element to push in the stack :");
            scanf("%d", &element);
            PUSH(element);
            break;
        case 2:
        { // there is  curly braces in the case   because if we declare a variable in case we need to keep the curly braces.
            int poppedElement = POP();
            if (poppedElement != -1)
                printf("\nPopped element is: %d\n", poppedElement);
            break;
        }

        case 3:
            // {
            // int check_Isfull = ISFULL();
            if (ISFULL())
            {
                printf("\nStack is full");
            }
            else
            {
                printf("\nStack is not full");
            }
            break;
        // }
        case 4:
            // {
            // int check_Isempty = ISEMPTY();

            if (ISEMPTY())
            {
                printf("\nStack is empty");
            }
            else
            {
                printf("\nStack is not empty");
            }
            break;
            // }

        case 5:
            return 0;
            break;

        default:
            printf("\nInvalid Option Selected");
            break;
        }
    }
}

// PUSH stack behavior
void PUSH(int a)
{
    if (S.TOS == MAX - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {

        S.TOS = S.TOS + 1;
        S.arr[S.TOS] = a;
        printf("\n %d is pushed into the stack", a);
    }
}

// Stack full check
int ISFULL()
{
    if (S.TOS == MAX - 1)
    {
        return 1;
    }
    else
        return 0;
}

// Stack empty check
int ISEMPTY()
{
    if (S.TOS == -1)
    {
        return 1;
    }

    else
        return 0;
}

// Pop stack behaviour
int POP()
{
    if (S.TOS == -1)
    {
        printf("\nStack underflow\n");
        return -1;
    }
    else
    {
        int popped = S.arr[S.TOS];
        S.TOS--;
        return popped;
    }
}