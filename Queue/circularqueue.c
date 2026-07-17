#include <stdio.h>

#define N 5

int queue[N];
int front = -1;
int rear = -1;

// Enqueue
void enqueue(int x)
{
    if ((rear + 1) % N == front)
    {
        printf("Queue Overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

// Dequeue
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow\n");
    }
    else if (front == rear)
    {
        printf("Deleted Element = %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted Element = %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

// Peek
void peek()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front Element = %d\n", queue[front]);
    }
}

// Display
void display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");

    int i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % N;
    }

    printf("\n");
}

// Main
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    peek();

    return 0;
}
