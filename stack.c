#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int top;
    int capacity;
    int *arr;
} Stack;

// Create Stack
Stack *createStack(int capacity)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));

    if (s == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    s->capacity = capacity;
    s->top = -1;
    s->arr = (int *)malloc(capacity * sizeof(int));

    if (s->arr == NULL)
    {
        printf("Memory allocation failed!\n");
        free(s);
        exit(1);
    }

    return s;
}

// Push
int push(Stack *s, int data)
{
    if (s->top == s->capacity - 1)
    {
        printf("Stack Overflow!\n");
        return -1;
    }

    s->arr[++s->top] = data;
    return 0;
}

// Pop
int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }

    return s->arr[s->top--];
}

// Peek
int peek(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is Empty!\n");
        return -1;
    }

    return s->arr[s->top];
}

// Display
void display(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is Empty!\n");
        return;
    }

    printf("Stack Elements: ");

    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }

    printf("\n");
}

// Size
int size(Stack *s)
{
    return s->top + 1;
}

// Delete Stack
void deleteStack(Stack *s)
{
    if (s == NULL)
        return;

    free(s->arr);
    free(s);
}

int main()
{
    Stack *s = createStack(5);

    push(s, 10);
    push(s, 20);
    push(s, 30);

    display(s);

    printf("Top Element: %d\n", peek(s));
    printf("Popped Element: %d\n", pop(s));
    printf("Current Size: %d\n", size(s));

    display(s);

    deleteStack(s);

    return 0;
}
