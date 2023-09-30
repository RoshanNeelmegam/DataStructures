// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void addLast(int val){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL){
        head = newnode;
        head->prev = NULL;
        head->next = NULL;
    }
    else {
       struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void addFirst(int val){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    if (head == NULL){
        head = newnode;
        head->next = NULL;
    }
    else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void printNode(struct node *head){
     if (head == NULL){
         printf("Node are not there\n");
     }
     struct node *temp = head;
     while (temp != NULL){
         printf("%d ", temp->data);
         temp = temp->next;
     }    
     printf("\n");
}


void deleteNodes(int val){
    struct node *temp = head;
    if (head->data == val){
        head = head->next;
        if (head != NULL){
         head-> prev = NULL;
        }
        free(temp);
    }
 
    else {
        while (temp != NULL){
            if (temp->data == val){
                struct node *current = temp->prev;
                current->next = temp->next;
                if (temp->next != NULL){
                  temp->next->prev = temp->prev;
                }
                free(temp);
                return;
        }
            temp = temp->next;
        }
         printf("Node not present\n");
    }
}



int main() {
    // Write C code here
    addFirst(10);
    addFirst(5);
    addFirst(2);
    addLast(20);
    addLast(30);
    printNode(head);
    deleteNodes(2);
    printNode(head);
    deleteNodes(300);
    printNode(head);

    return 0;
}
