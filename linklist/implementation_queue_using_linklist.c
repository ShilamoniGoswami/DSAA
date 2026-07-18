#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if (front == 0 && rear == 0)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void display()
{
    struct node *temp;
    if (front == 0 && rear == 0)
    {
        printf("The queue is empty!");
    }
    else
    {
        temp = front;
        printf("\nThe queue elements are: ");
        while (temp != 0)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("The queue is empty!\n");
    }
    else
    {
        printf("\nThe delete element is %d\n", front->data);
        front = front->next;
        free(temp);
    }
}
void peak()
{
    if (front == 0 && rear == 0)
    {
        printf("The queue is empty!\n");
    }
    else
    {
        printf("\nThe peak element is %d", front->data);
    }
}
int main()
{
    enqueue(5);
    enqueue(4);
    enqueue(3);
    display();
    dequeue();
    peak();
    dequeue();
    display();

    return 0;
}
