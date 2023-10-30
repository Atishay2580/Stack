// Prefix Evaluation Expression
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define STACKSIZE 100
#define True 1
#define False 0

// Define a structure for a stack
struct stack
{
    char item[STACKSIZE]; // Array to store stack elements
    char top;            // Index of the top element
};

// Function to initialize the stack
void intialization(struct stack *S)
{
    S->top = -1; // Initialize the top index to -1 (empty stack)
}

// Function to check if the stack is empty
char isempty(struct stack *S)
{
    if (S->top == -1)
        return True; // Return True (1) if the stack is empty
    else
        return False; // Return False (0) if the stack is not empty
}

// Function to push an element onto the stack
void push(struct stack *S, char x)
{
    if (S->top == STACKSIZE - 1)
    {
        printf("Stack Overflow"); // Print an error message for stack overflow
        exit(1); // Exit the program with an error code 1
    }
    else
    {
        S->top = S->top + 1; // Increment the top index
        S->item[S->top] = x; // Push the element onto the stack
    }
}

// Function to get the top element of the stack
char stacktop(struct stack *S)
{
    char x = S->item[S->top]; // Get the top element of the stack
    return x;
}

// Function to pop (remove and return) the top element from the stack
char pop(struct stack *S)
{
    if (S->top == -1)
    {
        printf("Stack Underflow"); // Print an error message for stack underflow
        exit(2); // Exit the program with an error code 2
    }
    else
    {
        char x = S->item[S->top]; // Get the top element
        S->top = S->top - 1; // Decrement the top index to remove the element
        return x; // Return the popped element
    }
}

// Function to calculate the power of a number
int power(int a, int n)
{
    if (n == 0)
    {
        return 1; // Any number raised to the power of 0 is 1
    }
    else
    {
        int p = power(a, n / 2); // Calculate power recursively
        if (n % 2 == 0)
            return p * p; // If n is even, return a^(n/2) * a^(n/2)
        else
            return p * p * a; // If n is odd, return a^(n/2) * a^(n/2) * a
    }
}

// Function to evaluate an operation based on the operator
int Evaluation(int a, int b, char symb)
{
    switch (symb)
    {
    case '+':
        return a + b; // Addition
    case '-':
        return a - b; // Subtraction
    case '*':
        return a * b; // Multiplication
    case '/':
        return a / b; // Division
    case '%':
        return a % b; // Modulo
    case '^':
        return power(a, b); // Power operation
    }
}

// Function to evaluate a prefix expression
int prefixevaluation(char prefix[])
{
    int i, symb, a, b, value, answer, l = strlen(prefix);
    struct stack S;
    intialization(&S); // Initialize the stack

    for (i = l - 1; i >= 0; i--)
    {
        symb = prefix[i];
        if (symb >= '0' && symb <= '9')
            push(&S, symb - '0'); // Push operands onto the stack
        else
        {
            a = pop(&S); // Pop the top two operands
            b = pop(&S);
            value = Evaluation(a, b, symb); // Evaluate the operation
            push(&S, value); // Push the result back onto the stack
        }
    }

    answer = stacktop(&S); // The final result is on the top of the stack
    return answer;
}

int main()
{
    int answer, x;
    char prefix[20];
    printf("Enter the expression\n");
    scanf("%s", prefix);
    x = prefixevaluation(prefix); // Evaluate the prefix expression
    printf("Evaluated Result for Prefix Expression is:=> %d", x);
}
