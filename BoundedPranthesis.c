#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 101
int arr[MAX];
int top = -1;


void push(char x)
{
    if (top == MAX - 1)
    {
        printf("\n OVERFLOW......");
        return;
    }
    arr[++top] = x; 
}

void pop()
{
    if (top == -1)
    {
        printf("\n No element is there to be removed....");
        return;
    }

    top--;
}
char Top()
{
    return arr[top];
}
int IsMatchFunc(char para)
{
    if ((Top()=='{')&&(para=='}'))
    {
        return 1;
    }
    else if ((Top()=='[')&&(para==']'))
    {
        return 1;
    } 
    else if ((Top()=='(')&&(para==')'))
    {
        return 1;
    }  
    else
    {
        return 0;
    }
    
    
}
int check(char *para,int n)
{
    int key=1;
    for (int i = 0; i < n; i++)
    {
        if ((para[i]=='{')||(para[i]=='[')||(para[i]=='('))
        {
            push(para[i]);
        }
        else if ((para[i]=='}')||(para[i]==']')||(para[i]==')'))
        {
            //printf("\n%c",Top());
            if (IsMatchFunc(para[i]))
            {
                pop();
            }
            else
            {
                key=0;
            }
            
        }        
    }
    return key;
}

int main()
{
    //int n;
    //printf("Enter a number");
    //scanf("%d",&n);
    char para[]="{{[]}}";
    //printf("\n enter the paranthesis . ");
    //scanf("%s",para);
     unsigned int n = sizeof(para)/sizeof(para[0]);
    int ans=check(para,n);
    printf("%d",ans);
    if (ans==1)
    {
        printf("\nThere is a bounded pranthesis.....");
    }
    else
    {
        printf("\nThere is no bounded paranthesis!!!!");
    }
    
    
    return 0;
}
