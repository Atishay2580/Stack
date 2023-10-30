// WAP to reverse a string using stack

#include <stdio.h>
#define SIZE 50

typedef struct stack
{
    char arr[SIZE];
    int top;
} stack;

stack stk; // creating an object of structure

int isEmpty()
{
    return stk.top == -1; // return boolean
}

int isFull()
{
    return stk.top == SIZE - 1; // return boolean
}

void push(int num)
{
    if (!isFull())
    {
        stk.top++;
        stk.arr[stk.top] = num; // inserting an element
    }
    else
    {
        printf("Stack overflow\n"); // stacl is full
    }
}

int pop()
{
    if (!isEmpty())
    {
        int item;
        item = stk.arr[stk.top];
        stk.top--;
        return item;
    }
    else
    {
        printf("stack is full");
        
    }
}

void show()
{
    if (!isEmpty()) // if the stack is not empty
    {
        for (int i = stk.top; i >= 0; i--)
        {
            printf("%d\n", stk.arr[i]);
        }
    }
    else
    {
        printf("Stack is empty");
    }
}

int peep()
{
    return stk.arr[stk.top];
}


int main()
{
    stk.top = -1;
    char stk[SIZE];
    char reverse[SIZE];
    printf("Enter any string: ");
    gets(stk);
    int i=0;
    while(stk[i]!='\0'){
        push(stk[i]);
        i++;
    }
    i=0;
    while(!isEmpty()){
        reverse[i] = pop();
        i++;
    }
    reverse[i] = '\0';
    printf("Reverse = %s\n", reverse);

    i=0;
    int flag = 0;
    while(reverse[i]!='\0'){
            flag =0;
        if(reverse[i] == stk[i]) flag = 1;
        i++;
    }
    if(flag==1){
        printf("palindrome");
    }
    else{
        printf("Not a palindrome");
    }

    return 0;
}