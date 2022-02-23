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


void Push()
{
    
    struct node *newnode = Create();
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next=head;
    head=newnode;
}
void Pop()
{
    struct node *temp = head;
    if (head==NULL)
    {
        printf("No element to be deleted !");
        return;
    }
    head=temp->next;
    free(temp);
    printf("Node Deleted !");
}
void Top()
{
    struct node *temp = head;
    printf("The element in the top is: %d", temp->data);

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
        printf("1.Push \n 2.Pop \n 3.Top \n 4.Display \n 5.Exit \n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Top();
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
