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
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    if (head == NULL){
        head = newnode;
        head->prev = NULL;
        head->next = NULL;
    }
    else {
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        head = newnode;
    }
    
}

void printList()
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    addFirst(10);
    addFirst(20);
    addFirst(30);
    
    printList();
}
