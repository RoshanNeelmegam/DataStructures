// Online C compiler to run C program online
#include <stdio.h>

struct node{
        int data;
        struct node *next;
};
    
struct node *head = NULL;
    
void addStart(val){
    struct node *firstnode = malloc(sizeof(struct node));
    firstnode->data = val;
    firstnode->next = NULL;
    if(head != NULL){
        firstnode->next = head;
    }
    head = firstnode;
}

void addEnd(val){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    
    struct node *temp;
    temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

int delNode(key){
    struct node *temp;
    if (head->data == key){
        temp = head;
        printf("%p\n", *temp);
        head = head->next;
        free(temp);
        printf("%p\n", *temp);
    }
    else {
        temp = head;
        struct node *current;
        while (temp->next->data != key){
            temp = temp->next;
        }
        current = temp;
        temp = temp->next;
        current->next = current->next->next;
        free(temp);
    }
    return 0;
}

int main() {
    
    // creating a c program to play with singly linked lists.
    addStart(30);
    addStart(20);
    addStart(10);
    addEnd(40);
    addEnd(50);
    delNode(10);
    
    struct node *temp;
    temp = head;
    while (temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    
    
    return 0;
}
