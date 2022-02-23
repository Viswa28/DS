#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;

struct node *Create()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the data to be inserted: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void insert()
{
   struct node* newnode = Create();
   struct node *temp = head;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode->prev = head;
    temp->next = newnode;
    printf("Newnode created!!");
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
        printf("Doubly Linked List \n");
        printf("1.Create \n 2.Display \n 3.Exit \n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            Display();
            break;
        case 3:
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
