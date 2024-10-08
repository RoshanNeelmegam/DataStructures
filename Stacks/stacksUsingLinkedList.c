#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(int val)
{
    //Task 1: Correct the below code
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

int pop()
{
    //Implement Task 2 here
    if (head == NULL){
        return -1;
    }
    else {
        struct node *temp = head;
        int popped_item = head->data;
        head = head->next;
        free(temp);
        return (popped_item);
    }
    
}

int main()
{
    push(10);
    push(20);
    push(30);
    printf("%d ",pop());
    printf("%d ",pop());
    push(40);
    printf("%d ",pop());
    printf("%d ",pop());
    printf("%d ",pop());

    return 0;
}
