#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max 5

struct Queue
{
    int front;
    int rear;
    int data[max];

} Q = {0, -1};

// function declaration or prototype
void Enqueue(int element);
int Dequeue();
bool Isempty();
bool Isfull();

int main()
{
    int element, input;
    while (1)
    {
        printf("\n\nChoose what you want to do:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. ISFULL CHECK\n");
        printf("4. ISEMPTY CHECK\n");
        printf("5. Exit\n");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("\nEnter the element to enter in the queue :");
            scanf("%d", &element);
            Enqueue(element);
            break;
        case 2:
        {
            int d_val = Dequeue();
            if (d_val != -1)
                printf("\n%d is dequeued", d_val);
            break;
        }

        case 3:
            if (Isempty())
            {
                printf("\nQueue is empty");
            }
            else
            {
                printf("\nQueue is not empty");
            }
            break;

        case 4:
            if (Isfull())
            {
                printf("\nQueue is full");
            }
            else
            {
                printf("\nQueue is not full");
            }
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\nwrong choice selected!!");
            break;
        }
    }

    return 0;
}

void Enqueue(int element)
{
    if (Q.rear == max - 1)
    {
        printf("\nQueue is Full");
    }
    else
    {
        Q.rear = Q.rear + 1;
        Q.data[Q.rear] = element;
        printf("\n %d is entered into the queue", element);
    }
}

int Dequeue()
{
    if (Q.front > Q.rear)
    {
        printf("\nQueue is empty");
        return -1;
    }
    else
    {
        int el = Q.data[Q.front];
        Q.front = Q.front + 1;
        return el;
    }
}

bool Isempty()
{
    if (Q.front > Q.rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Isfull()
{
    if (Q.rear == max - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}