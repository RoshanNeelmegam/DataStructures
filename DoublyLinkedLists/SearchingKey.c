#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

int search(struct node *last, int key)
{
    //Write your code here // Here only *last is used as we dont need to modify but just traverse.
    struct node *temp = last; 
    while (temp != NULL){
        if (temp->data == key){
            return 1;
        }
        temp = temp->prev;
    }
    return -1;
    
}

//Don't change the below code //Here ** is used for call by reference, where we need to modify the head's value.
void addFirst(struct node **head, int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;

    if(*head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        *head = newNode;
    }
    else
    {
        newNode->prev = NULL;
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

int main()
{
    struct node *head = NULL, *last;

    addFirst(&head,10);
    last = head;
    addFirst(&head,20);
    addFirst(&head,30);
    addFirst(&head,40);

    int key;
    scanf("%d",&key);

    printf("%d",search(last, key));

    return 0;
}
