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
void initialization(struct stack *S)
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
