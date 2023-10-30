#include <stdio.h>
#define SIZE 10

typedef struct stack
{
    int arr[SIZE];
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

void dec2Bin(int num){
    stk.top = -1;
    while(num>0){
        int r = num%2;
        push(r);
        num = num/2;
    }
    printf("Binary equivalent = ");
    while(!isEmpty()){
        printf("%d", pop());
    }
}

void dec2oct(int num){
    stk.top = -1;
    while(num>0){
        int r = num%8;
        push(r);
        num = num/8;
    }
    printf("octal equivalent = ");
    while(!isEmpty()){
        printf("%d", pop());
    }
}

void dec2Hexa(int num){
    char digits[] = "0123456789ABCDEF";
    stk.top = -1;
    while(num>0){
        int r = num%16;
        push(r);
        num = num/16;
    }
    printf("Hexadecimal equivalent = ");
    while(!isEmpty()){
        printf("%c", digits[pop()]);
    }
}



int main()
{
    stk.top = -1;
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    dec2Bin(num);
    printf("\n");
    dec2oct(num);
    printf("\n");
    dec2Hexa(num);

     

    return 0;
}