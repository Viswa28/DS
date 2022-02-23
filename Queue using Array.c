#include <stdio.h>
#include <stdlib.h>
#define MAX 101
int Queue[MAX];
int front = -1, rear = -1;

void Enqueue()
{
    int x;
    printf("Enter the element to be pushed : ");
    scanf("%d", &x);
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    Queue[rear] = x;
}
void Dequeue()
{
    if (front == -1)
    {
        printf("No element to be deleted !");
        return;
    }
    if (front == rear)
    {
        front = rear - 1;
    }
    else
    {
        front += 1;
    }
}

void Display()
{
    for (int Front = front; Queue[Front] != '\0'; Front++)
    {
        printf(" %d->", Queue[Front]);
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