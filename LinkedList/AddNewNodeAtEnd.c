#include<stdio.h>
#include<stdlib.h>

struct node
{   
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *end = NULL;
struct node *PreviousN = NULL;
void addLast(int val)
{
    //Write your code here
    //My Solution
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    end = newnode;
    if(PreviousN == NULL){
        head = newnode;
        PreviousN = newnode;
    }
    else if(PreviousN != NULL){
        PreviousN->next = end;
        PreviousN = newnode;
    }
    //My Solution

    //Other Solution
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    
    if(head == NULL){
        head = newnode;
    }
    else {
        struct node *lastnode = head;
        while (lastnode->next != NULL){
            lastnode = lastnode->next;
        }
        lastnode->next = newnode;
    }
    //Other Solution

}

//Don't change the below code
void printList()
{
    struct node *temp = head;

    while(temp != NULL)
    {
         printf("%d ", temp->data);
         temp = temp->next;
    }
}

int main()
{
     addLast(10);
     addLast(20);
     addLast(30);

     printList();

     return 0;
}
