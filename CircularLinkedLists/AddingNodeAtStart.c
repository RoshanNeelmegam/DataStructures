#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void addFirst(int val)
{
    //Write your code here
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;

    if(head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void printList()
{
    struct node *temp = head;

    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != head);
}

int main()
{
    addFirst(10);
    addFirst(20);
    addFirst(30);
    
    printList();
}
