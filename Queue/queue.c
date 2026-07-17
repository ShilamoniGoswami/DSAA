#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct
{
    int arr[SIZE];
    int front;
    int rear;
} Queue;

// Create Queue
void createQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Check Empty
int isEmpty(Queue *q)
{
    return (q->front == -1);
}

// Check Full
int isFull(Queue *q)
{
    return (q->rear == SIZE - 1);
}

// Enqueue
void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
        return;
    }

    if (isEmpty(q))
        q->front = 0;

    q->rear++;
    q->arr[q->rear] = value;
}

// Dequeue
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = q->arr[q->front];

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }

    return value;
}

// Front
int front(Queue *q)
{
    if (isEmpty(q))
        return -1;

    return q->arr[q->front];
}

// Display
void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }

    printf("\n");
}

// Main
int main()
{
    Queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    printf("Deleted = %d\n", dequeue(&q));

    display(&q);

    printf("Front = %d\n", front(&q));

    return 0;
}
