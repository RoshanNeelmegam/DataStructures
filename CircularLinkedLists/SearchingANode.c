#include<stdio.h>
#include<stdlib.h>

struct node
{   
    int data;
    struct node *next;
};

struct node *head = NULL;

int search(int key)
{   
    //Write your code here
    struct node *temp = head;
    if (head == NULL){
        return;
    }
    else {
        do{
        if (temp -> data == key){
            return 1;
        }
            temp = temp->next;
        }while (temp != head);
        return -1;
    }
    
}

void addLast(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;

    if(head == NULL)
    {
        head = newNode;
        newNode->next = newNode;
    }
    else
    {
        struct node *temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

int main()
{
    addLast(10);
    addLast(20);
    addLast(30);

    int key;
    scanf("%d",&key);

    printf("%d",search(key));

    return 0;
}
