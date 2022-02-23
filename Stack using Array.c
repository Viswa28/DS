#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int Stack[MAX];
int top = -1;

void Push()
{
    int x;
    printf("Enter the element to be pushed : ");
    scanf("%d", &x);
    if (top == MAX - 1)
    {
        printf("OVERFLOW!!!");
        return;
    }
    Stack[++top] = x;
}
void Pop()
{
    if (top == -1)
    {
        printf("No element to be deleted!");
        return;
    }
    top--;
}
void Top()
{
    if (top == -1)
    {
        printf("No element to deleted!");
    }

    printf("The element in the top is: %d", Stack[top]);
}

void Display()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", Stack[i]);
    }
   // printf("NULL");
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
