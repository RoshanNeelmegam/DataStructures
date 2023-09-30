#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

int search(struct node *root, int key)
{
    //Write your code here
    if (root == NULL){
        return 0;
    }
    else if (root->key == key){
        return 1;
    }
    if (root->key > key){
        search(root->left, key);
    }
    else if (root->key < key){
        search(root->right, key);
    }
    
}

//Don't change the below code
struct node *getNewNode(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int val)
{
    if(root == NULL)
        return getNewNode(val);
    if(root->key < val)
        root->right = insert(root->right,val);
    else if(root->key > val)
        root->left = insert(root->left,val);

    return root;
}

int main()
{
    struct node *root = NULL;
    root = insert(root,100);
    root = insert(root,50);
    root = insert(root,200);
    root = insert(root,150);
    root = insert(root,300);

    int key;
    scanf("%d",&key);
    search(root,10);
    printf("%d",search(root,key));

    return 0;
}
