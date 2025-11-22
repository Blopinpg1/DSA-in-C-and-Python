#include<stdio.h>
#include<stdlib.h>
typedef struct stackUsingSll
{
 int data;
 struct stackUsingSll *next;
} Stack;
Stack *first,*last=NULL;

void push(int element){
Stack *newnode=(Stack*)malloc(sizeof(Stack));
if (newnode==NULL)
{
    printf("Memory allocation failed");
    return;
}
newnode->data = element;
newnode->next = NULL;
if (first==NULL)
{
     first=last=newnode;
}
else{
    newnode->next = first;
    first = newnode;
}
}

void pop(){

    if (first == NULL)
    {
        printf("The stack  is empty.\n");
        return;
    }
  if(first->next ==NULL)
  {
    Stack *temp = first;
    printf("%d is popped from the stack\n",first->data);
    first = last = NULL;
    free(temp);
  }
  else{
    Stack *temp = first;
printf("%d is popped from the stack\n",first->data); 
first = first->next;
free(temp);

  }
}


void display()
{
     if (first == NULL)
    {
        printf("Stack is empty\n");
    }

   else{
     Stack *temp=first;
    while (temp!=NULL)
    {
       printf("%d->",temp->data);
       temp= temp->next;
    }
    printf("NULL");
    printf("\n");
    }
}



int main()
{
    push(2);
    display();
    push(5);
    display();
    push(10);
    display();
    pop();
    display();
    return 0;
}

