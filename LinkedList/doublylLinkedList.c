#include <stdio.h>
#include <stdlib.h>

typedef struct DLL
{
    int data;
    struct DLL *prev, *next;
} D;

D *first, *last = NULL;

// Doubly linked list

void insertionFromThBeginning(int element)
{
    D *newnode = (D *)malloc(sizeof(D));
    if (newnode == NULL)
        printf("Memory allocation failed!");

    newnode->data = element;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (first == NULL)
    {
        first = last = newnode;
    }

    else
    {
        newnode->next = first;
        first->prev = newnode;
        first = newnode;
    }
    printf("\n%d was inserted at the front\n", first->data);
}

void insertionFromEnd(int element)
{
    D *newnode = (D *)malloc(sizeof(D));
    if (newnode == NULL)
        printf("Memory allocation failed!");

    newnode->data = element;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (first == NULL)
    {
        first = last = newnode;
    }

    else
    {
        newnode->prev = last;
        last->next = newnode;
        last = newnode;
    }
    printf("\n%d was inserted at the end\n", last->data);
}

void InsertFromSpecificPosition( int pos ,int element)
{
    D *temp=first;
 
if (pos==1)
{
    insertionFromThBeginning(element);
    return;

}

for (int i = 1; i<pos-1; i++)
{
    
     if (temp == NULL)
     {
            printf("Position out of bounds.\n");
            return;
    }
    temp = temp->next;
}

if(temp->next == NULL)
{
insertionFromEnd(element);
return;
}

else{
D *newnode;
newnode = (D*)malloc(sizeof(D));
if(newnode==NULL)
{
    printf("memory allocation failed");
    return;
}
newnode->data = element;
newnode->next = temp->next; 
newnode->prev =temp; 
temp->next->prev =newnode;
temp->next = newnode;
}
}
void deletionFromTheBeginning()
{
    
    if (first == NULL)
    {
        printf("Empty list");
        return;
    }
   D *temp=first;
    if (first->next == NULL)
    {

        printf("\n%d is going to be deleted\n", temp->data);
        first = last = NULL;
    }
    else
    {
        printf("\n%d is going to be deleted\n", temp->data);
        first = first->next;
        first->prev = NULL;
    }
    free(temp);
}

void deletionFromTheEnd()
{
    D *temp=last;
    if (first == NULL)
        printf("Empty list");
        return;

    if (first->next == NULL)
    {
        first = last = NULL;
        printf("\n%d is going to be deleted\n", temp->data);
    }

    else
    {
        printf("\n%d is being deleted from the list\n", temp->data);
        last = last->prev;
        last->next =NULL;
    }
    free(temp);
}

void DelFromSpecificPosition(int pos)
{
    D *temp=first;
 
if (pos==1)
{
    deletionFromTheBeginning();
    return;

}

for (int i = 1; i<pos-1; i++)
{
    
     if (temp == NULL)
     {
            printf("Position out of bounds.\n");
            return;
    }
    temp = temp->next;
}
D *tempp =temp->next;

     if (tempp == NULL)
     {
            printf("Position out of bounds.\n");
            return;
    }


if(tempp->next == NULL)
{
deletionFromTheEnd();
return;
}

temp->next = tempp->next;
tempp->next->prev = temp;

  if (tempp == last)
        last = temp;

        
free(tempp);

}

void searching(int key)
{
    int flag = 0;
    D *temp = first;
    if (first = NULL)
        printf("\nEmpty list\n");

    else
    {
      
        while (temp != NULL)
        {
            if (temp->data = key)
            {
                printf("\nElement found\n");
                flag = 1;
            }
            temp = temp->next;
        }

        if (flag = 0)
        {
            printf("Search unsuccessful\n");
        }
    }
}

void displayReverse()
{
    D *temp = last;
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d <-> ", temp->data);
            temp = temp->prev;
        }
        printf("NULL");
    }
}

void display()
{
    D *temp = first;
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {

        while (temp != NULL)
        {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL");
         printf("\n");
    }
   
}

int main()
{
    insertionFromThBeginning(20);
    display();
    insertionFromEnd(46);
    display();
    insertionFromEnd(22);
    display();
    insertionFromEnd(33);
    display();
   DelFromSpecificPosition(2);
    display();

    return 0;
}


// 1.Implemnt remaining operators in DLL
// 2.Implemet stacks using sll
//3.Reverse a linked list (SLL/DLL)