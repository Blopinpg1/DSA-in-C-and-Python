#include <stdio.h>
#include <stdlib.h>

struct CLL
{
    int data;
    struct CLL *next, *prev;
};
struct CLL *first, *last;

void insert_From_Beginning(int element)
{
    printf("\nInserting %d at the beginning of the linked list.\n", element);
    struct CLL *new_node = (struct CLL *)malloc(sizeof(struct CLL));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = element;
    new_node->next = NULL;

    if (first == NULL) // empty list
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        first = last = new_node;
    }
    else
    {
        new_node->next = first;
        new_node->prev = last;
        last->next = new_node;
        first = new_node;
    }
}

void insert_From_End(int element)
{
    printf("\nInserting %d at the end of the linked list.\n", element);
    struct CLL *new_node = (struct CLL *)malloc(sizeof(struct CLL));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = element;
    new_node->next = NULL;

    if (first == NULL) // empty list
    {
        new_node->next = new_node;
        new_node->prev = new_node;



        first = last = new_node;
    }
    else{
        new_node->next =first;
        new_node->prev =last;
        last->next =new_node;
        first->prev =new_node;
        last =new_node;

    }



}

void display()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct CLL *temp = first;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf("(%d)\n", first->data);
}

int main()
{
    insert_From_Beginning(10);
    display();
    insert_From_Beginning(20);
    display();
    insert_From_Beginning(30);
    display();
    insert_From_Beginning(40);
    display();
    insert_From_End(50);
    display();
}