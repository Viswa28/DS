#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
int Stack[MAX];
int top = -1;

void push(int x)
{

    Stack[++top] = x;
}
char Top()
{
    if (top == -1)
    {
        return '\0';
    }

    return Stack[top];
}
int pop()
{
    int pop_val = Top();
    top--;
    return pop_val;
}
int isEmpty()
{
    return (top == -1);
}
int HighPrece(char top, char val)
{
    if (((top == '+') || (top == '-')))
    {
        return 0;
    }
    else if (((top == '*') || (top == '/')))
    {
        return 1;
    }
    return -1;
}
void ToPostfix(char *exp, int n)
{
    
    //int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (isdigit(exp[i]))
        {
            printf("%C",exp[i]);
        }
        else if (!isdigit(exp[i]))
        {
            
            while ( (HighPrece(Top(), exp[i])==1))
            {
               while (!isEmpty())
            {
                char top = Top();
                printf("%c",top);
                pop();
            }
            }
            push(exp[i]);

            
        }
    }
      while (!isEmpty())
            {
                char top = Top();
                printf("%c",top);
                pop();
            }
}
int main()
{
    char exp[] = "2+3+2+5+4";
    //printf("Enter the experssion to evaluate....\n");
    //scanf("%s",exp);
    //int n=sizeof(exp)/sizeof(exp[0]);
    int n = 10;
    ToPostfix(exp, n);
     
    return 0;
}
