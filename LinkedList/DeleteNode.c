// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void addLast(struct node **headptr, int val){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    if (*headptr == NULL){
        *headptr = newnode;
        (*headptr)->next=NULL;
    }  
    else{
        struct node *temp = *headptr;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void printList(struct node **headptr){
    struct node *temp = *headptr;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void delNode(struct node **headptr, int val){
    struct node *temp = *headptr;
    if (temp->data == val){
        *headptr = temp->next;
        free(temp);
    }
    else{
        while (temp->next->data != val){
            temp = temp->next;
            if (temp->next== NULL){
                temp = temp->next;
                break;
            }
        }
        if (temp!=NULL){
            struct node *current = temp;
            temp = temp->next;
            if (temp!=NULL){
                current->next = temp->next;
            }
            else{
                current->next = NULL;
            }
        }
        else{
            printf("Node not found");
        }
    }
}


int main() {
    // Write C code here
    struct node *head = NULL;
    addLast(&head, 10);
    addLast(&head, 20);
    addLast(&head, 30);
    printList(&head);
    printf("\n");
    delNode(&head, 60);
    printf("\n");
    printList(&head);

    return 0;
}
