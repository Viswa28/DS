#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 101
int Stack[MAX];
int top=-1;

void push(int x)
{

    Stack[++top]=x;
}
int Top()
{
    return Stack[top];
}
int pop()
{
    int pop_val=Top();
    top--;
    return pop_val;
}



int performOperation(char operator,int a,int b)
{
    switch (operator)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    }
}
int EvaluateExpression(char exp[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        if(isdigit(exp[i]))
        {
            push( exp[i] - '0');
        }
        else if (!(isdigit(exp[i])))
        {
            int op2=pop();
            int op1=pop();
            int result=performOperation(exp[i],op1,op2);
            push(result);
        }
        
    }
   int ans=Top();
   return ans; 
  
}
int main()
{
    char exp[]="23*54*+9-";
    printf("Enter the experssion to evaluate....\n");
    //scanf("%s",exp);
    //int n=sizeof(exp)/sizeof(exp[0]);
    int n=10;
    int value=EvaluateExpression(exp,n);
    printf("The the Value is: %d ",value);
    return 0;

}