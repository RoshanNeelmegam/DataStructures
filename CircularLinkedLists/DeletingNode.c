#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void deleteNode(int key)
{ 
    
    //Write your code here
    // 3 scenarios: key at head, key at middle, key at end
    struct node *temp = head;
    struct node *current;
    // for scenario 1
    if (head->data == key){
        while (temp->next != head){
            temp=temp->next;
        }
        current = temp;
        temp = head;
        head = head->next;
        current->next=head;
        free(temp);
    }
    // for scenario 2 and 3
    else{
        while(temp->next->data != key || temp->next == head){
            temp = temp->next;
            }
        if (temp->next->data == key){
            current = temp;
            temp = temp->next;
            current->next = temp->next;
            free(temp);
            }
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
    
    int key;
    scanf("%d",&key);

    deleteNode(key);
    printList();

    return 0;
}
