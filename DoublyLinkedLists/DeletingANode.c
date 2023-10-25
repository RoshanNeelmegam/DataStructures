#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

void deleteNode(struct node **head, int key)
{
    //Write your code here 
    struct node *temp;
    if ((*head)->data == key){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    else {
        temp = *head;
        while (temp != NULL){
            if (temp->data == key){
                temp->prev->next = temp->next;
                if (temp->next != NULL){
                    temp->next->prev = temp->prev;
                }
                free(temp);
            }
            temp = temp->next;
        }
    }
    
    
}


// Another method
// void delNode(struct node **headptr, int val){
//     struct node *temp = *headptr;
//     if ((*headptr)->data == val){
//         *headptr = (*headptr)->next;
//         if (*headptr != NULL){
//             (*headptr)->prev = NULL;
//         }
//         free(temp);
//     }
//     else {
//         while (temp->next->data != val){
//             temp = temp->next;
//             if (temp->next == NULL){
//                 printf("Element not found\n");
//                 return;
//             }
//         }
//         struct node *current = temp;
//         temp = temp->next;
//         if (temp != NULL){
//             current->next = temp->next;
//             if (temp->next != NULL){
//               temp->next->prev = current;
//             }
//             free(temp);
//             return;
//         }
//         else{
//             current -> next = NULL;
//             free(temp);
//             return;
//         }
//     }
// }
    


//Don't change the below code
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

void printList(struct node* head)
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
    struct node *head = NULL;

    addFirst(&head,10);
    addFirst(&head,20);
    addFirst(&head,30);
    addFirst(&head,40);

    int key;
    scanf("%d",&key);

    deleteNode(&head, key);
    printList(head);

    return 0;
}
