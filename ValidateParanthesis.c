#include<stdio.h>
#include<string.h>
#define SIZE 100
typedef struct stack
{
    int top;
    int data[SIZE];
}stack;

stack stk;

int isEmpty()
{
    return stk.top == -1;
}

int isFull()
{
    return stk.top == SIZE -1;
}

void push(int item)
{
    if(!isFull())
    {
        stk.top++;
        stk.data[stk.top] = item;
    }
}
int pop()
{
    if(!isEmpty())
    {
        return stk.data[stk.top--];
    }
}

int peep()
{
    if(!isEmpty())
    {
        return stk.data[stk.top];
    }
}
int getCode(char b)
{
    switch (b)
    {
    case '(':
        return 1;
    case ')':
        return -1;
    case '{':
        return 2;
    case '}':
        return -2;
    case '[':
        return 3;
    case ']':
        return -3;
    }

}
int validateParenthesis(char expr[])
{
    stk.top = -1;
    int i=0;
    while(expr[i]!='\0')
    {
        char b = expr[i];
        if(getCode(b)>0)
        {
            push(b);
        }
        else{
            if(!isEmpty())
            {
                if(getCode(b)+getCode(peep()) == 0)
                {
                    pop();
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
        i++;
    }
    return isEmpty();

}
int validateBrackets(char expr[])
{
    stk.top = -1;
    int i=0; 
    while(expr[i]!='\0')
    {
        char bracket = expr[i];
        if(bracket == '(')
        {
            push(bracket);
        }
        else if(bracket==')'){
            if(!isEmpty())
            {
                pop();
            }else{
                return 0;
            }
        }
        i++;
    }
    return isEmpty();
}

int main()
{
    stk.top = -1;
    char expr[100];
    printf("Enter any expression");
    gets(expr);
    if(validate(expr))
    {
        printf("Valid Expression");
    }
    else{
        printf("Invalid Expression");
    }
    return 0;
}