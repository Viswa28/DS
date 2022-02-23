#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;

struct node *Create()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the data to be inserted: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    printf("Newnode created!!");
    return newnode;
}

void Enqueue()
{
    //struct node *temp = front;
    struct node *newnode = Create();
    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
        return;
    }
    rear->next=newnode;
    rear=newnode;
}
void Dequeue()
{
    struct node *temp = front;
    if (front == NULL)
    {
        printf("No element to be deleted !");
        return;
    }
    if (rear==front)
    {
        front=rear=NULL;
    }
    else
    {
        front=front->next;
    }
    free(temp);
    printf("Node Deleted !");
}

void Display()
{
    struct node *temp = front;
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
        printf("1.Enqueue \n 2.Dequeue \n 3.Display \n 4.Exit \n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
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