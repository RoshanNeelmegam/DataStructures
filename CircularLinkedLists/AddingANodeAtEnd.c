#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void addLast(int val)
{
    //Write your code here
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    if (head == NULL){
        head = newnode;
        head -> next = head;
    }
    else{
        struct node *temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

void printList()
{
    if(head == NULL)
        return;

    struct node *temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;

    }while(temp != head);

}

int main()
{
    addLast(10);
    addLast(20);
    addLast(30);
    addLast(40);

    printList();

    return 0;
}
