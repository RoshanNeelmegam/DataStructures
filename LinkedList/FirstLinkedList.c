
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //since nodes hold heterogenous data types, we need a Struct
    struct node
    {
        int data;
        struct node *next;
    };

    //declaring nodes or pointers in stack
    struct node *a,*b,*c;

    //Implement task 1 here
    //Creating/allocating the required size in Heap. The pointers will point to the struct node in heap
    a = malloc(sizeof(struct node));
    b = malloc(sizeof(struct node));
    c = malloc(sizeof(struct node));
    //Whatever struct node the pointer is pointing, we need to assign a value to it's data part
    a->data = 100;
    b->data = 200;
    c->data = 300;

    //Implement task 2 here
    //Linking the nodes
    a->next = b;
    b->next = NULL;
    c->next = a;



    //Don't change the below code
    struct node *temp = c;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }

    return 0;
}
