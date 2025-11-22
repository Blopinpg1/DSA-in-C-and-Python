#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int postfix_Evaluator(char *expression);

int main()
{
    char expression_Holder[MAX_SIZE];

    printf("Enter the postfix expression : ");
    fgets(expression_Holder, sizeof(expression_Holder), stdin);

    int Result = postfix_Evaluator(expression_Holder);
    printf("The result of postfix expression  = %d\n", Result);
    // Example:  3 4 + 2 * 7 /   == 2

    return 0;
}

int postfix_Evaluator(char *expression)
{
    char *token = strtok(expression, " ");
    int stack[MAX_SIZE];
    int top = -1;

    while (token != NULL)
    {
        if (isdigit(token[0]))

            // Convert string to int and push to stack
            stack[++top] = atoi(token); // ascii to int conversion grna  lai "3" -->3

        else
        {

            int operand2 = stack[top--];
            int operand1 = stack[top--];

            switch (token[0])
            {
            case '+':
                stack[++top] = operand1 + operand2;
                break;
            case '-':
                stack[++top] = operand1 - operand2;
                break;
            case '*':
                stack[++top] = operand1 * operand2;
                break;
            case '/':
                stack[++top] = operand1 / operand2;
                break;
            }
        }
        token = strtok(NULL, " "); // if no tokens left then strtok() returns NULL and we exit  the loop
    }

    return stack[top];
}
