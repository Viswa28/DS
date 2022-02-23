#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node *Create()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the data to be inserted: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    printf("Newnode created!!");
    return newnode;
}

void insert_beg()
{
    struct node *newnode = Create();
    if (head == NULL)
    {
        head = newnode;
        return;
    }

    newnode->next = head;
    head = newnode;
}
void insert_last()
{
    struct node *temp = head;
    struct node *newnode = Create();
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void insert_nth()
{
    struct node *temp = head;
    struct node *newnode = Create();
    int pos;
    printf("Enter the position of the data to be inserted: ");
    scanf("%d", &pos);
    if (pos == 0)
    {
        insert_beg();
    }
    for (int i = 0; i < pos; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void Insert()
{
    int choice;
    printf("1.Insert beg \n 2.Insert nth \n 3.Insert last \n");
    printf("Enter your choice :");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        insert_beg();
        break;
    case 2:
        insert_nth();
        break;
    case 3:
        insert_last();
        break;
    default:
        printf("Enter valid choice ! ");
        break;
    }
}
void delete_beg()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("No node to be deleted !");
    }
    if (temp->next == NULL)
    {
        free(temp);
        printf("Node deleted!");
        return;
    }
    head = temp->next;
    free(temp);
    printf("Node deleted!");
}
void delete_last()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("No node to be deleted !");
        return;
    }
    if (temp->next == NULL)
    {
        free(temp);
        printf("Node deleted!");
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;

    free(temp);
    printf("Node deleted!");
}
void delete_nth()
{
    struct node *temp = head;
    int pos;
    printf("Enter the position of the data to be inserted: ");
    scanf("%d", &pos);
    if (pos == 0)
    {
        delete_beg();
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        //free(temp);
        printf("Node deleted!");
        return;
    }
}
void Delete()
{
    int choice;
    printf("1.delete beg \n 2.delete nth \n 3.delete last \n");
    printf("Enter your choice :");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        delete_beg();
        break;
    case 2:
        delete_nth();
        break;
    case 3:
        delete_last();
        break;
    default:
        printf("Enter valid choice ! ");
        break;
    }
}
void Display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main()
{
    int choice, ch;
    do
    {
        printf("Singly Linked List \n");
        printf("1.Create \n 2.Insert \n 3.Delete \n 4.Display \n 5.Exit \n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Create();
            break;
        case 2:
            Insert();
            break;
        case 3:
            Delete();
            break;
        case 4:
            Display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter valid choice ! ");
            break;
        }
        printf("\nDo you want continue (1|0) : ");
        scanf("%d", &ch);
    } while (ch);
    return 0;
}
