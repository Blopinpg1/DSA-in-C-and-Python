#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

struct sll
{
    int data;
    struct sll *next;
};

struct sll *first, *last = NULL;

void insert_From_Beginning(int element)
{
    printf("\nInserting %d at the beginning of the linked list.\n", element);
    struct sll *new_node = (struct sll *)malloc(sizeof(struct sll));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = element;
    new_node->next = NULL;

    if (first == NULL) // empty list
    {

        first = last = new_node;
    }

    else
    {
        new_node->next = first;
        first = new_node;
    }
}

int insert_From_End(int element)
{
    struct sll *new_node = (struct sll *)malloc(sizeof(struct sll));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return -1;
    }
    new_node->data = element;
    new_node->next = NULL; // setting the next pointer of new node to NULL

    if (first == NULL)
    {

        first = last = new_node;
        printf("\nInserted %d at the end of the linked list.\n", element);
        return new_node->data;
    }
    else
    {

        last->next = new_node; // previous last node's next pointer   point to new node
        last = new_node;       // now new node becomes the last node and last pointer  point to new node
        printf("\nInserted %d at the end of the linked list.\n", element);
        return new_node->data;
    }
}

void insert_At_Specific_Position(int element, int pos)
{
    struct sll *new_node = (struct sll *)malloc(sizeof(struct sll));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = element;
    new_node->next = NULL;

    if (pos < 1)
    {
        printf("\nInvalid position. Position should be greater than or equal to 1.\n");
        free(new_node);
        return;
    }

    if (first == NULL)
    {
        first = last = new_node;
    }

    else if (pos == 1)
    {
        insert_From_Beginning(element);
    }

    struct sll *temp = first;
    int i;
    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        insert_From_End(element);
    }

    else
    {
        new_node->next = temp->next;
        temp->next = new_node;
        printf("\nInserted %d at position %d.\n", element, pos);
    }
}

void display()
{
    if (first == NULL)
    {
        printf("list is empty\n");
    }

    else
    {
        struct sll *temp = first;
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL->");
    }
}

int deletion_from_beginning()
{
    if (first == NULL)
    {
        printf("The linked list is empty.\n");
        return -1;
    }
    else if (first->next == NULL)
    {
        struct sll *temp = first;
        first = last = NULL;

        free(temp);
    }
    else
    {
        struct sll *temp = first;
        first = first->next;
        free(temp);
    }
    printf("\nDeleted the first element from the linked list.\n");
    return 0;
}

int deletion_from_end()
{
    if (first == NULL)
    {
        printf("list is empty\n");
        return -1;
    }
    else if (first->next == NULL)
    {
        struct sll *temp = first;
        first = last = NULL;
        free(temp);
        printf("Deleted the last element from the linked list.\n");
        return 0;
    }
    else
    {
        struct sll *temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        last = temp;       // last now points to the second last node
        temp = temp->next; // temp now points to the last node
        last->next = NULL; // set the next pointer of the second last node to NULL
        free(temp);        // free the last node
        printf("\nDeleted the last element from the linked list.\n");
        return 0;
    }
}

void deletion_From_Specific_Position(int pos)
{
    struct sll *temp = first;
    struct sll *toDelete;
    int i;

    if (first == NULL)
    {
        printf("List is empty.\n");
    }
    else if (pos == 1)
    {
        deletion_from_beginning();
    }
    else
    {

        for (i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
        {
            printf("Invalid position.\n");
            return;
        }

        if (temp->next == last)
        {
            deletion_from_end();
        }
        else
        {
            toDelete = temp->next;
            temp->next = toDelete->next;
            printf("\nDeleted element %d from position %d.\n", toDelete->data, pos);
            free(toDelete);
        }
    }
}

void searching(int value)
{
    int flag = false;
    if (first == NULL)
    {
        printf("List is empty");
    }
    else
    {
        struct sll *temp;
        temp = first;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                flag = true;
                printf("\nElement found: %d", temp->data);
            }
            temp = temp->next;
        }
    }
    if (flag == 0)
    {
        printf("\nElement not found");
    }
}

void reversing_linked_list()
{
    struct sll *prev =NULL, *next = NULL;
    struct sll *current = first;
    while (current != NULL)
    {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev to current
        current = next;       // Move to next node
    }
    first = prev;
   
}


int main()
{
    insert_From_Beginning(200);
    display();
    insert_From_End(300);
    display();
    insert_From_End(900);
    display();
    // insert_At_Specific_Position(600, 3);
    // display();

    // deletion_From_Specific_Position(2);
    // display();
   searching(600);
    reversing_linked_list();
    printf("\nReversed linked list:\n");
    display();


    return 0;
}