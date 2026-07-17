#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int size;
} linkedlist;

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

linkedlist *createlinkedlist()
{
    linkedlist *list = (linkedlist *)malloc(sizeof(linkedlist));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void insertAtTail(linkedlist *list, int data)
{
    Node *newNode = createNode(data);

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;
}

void display(linkedlist *list)
{
    if (list->head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    Node *temp = list->head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    linkedlist *myList = createlinkedlist();

    insertAtTail(myList, 10);
    insertAtTail(myList, 20);
    insertAtTail(myList, 30);

    printf("Linked List Size: %d\n", myList->size);
    printf("Linked List Elements: ");
    display(myList);

    Node *current = myList->head;

    while (current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(myList);

    return 0;
}
