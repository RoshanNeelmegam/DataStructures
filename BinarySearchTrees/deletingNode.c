#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

int getRightMin(struct node *root)
{   
    struct node *temp = root;
    while (temp->left != NULL){
        temp = temp->left;
    }
    // printf("%d", temp->key);
    return temp->key;
}

struct node *delnode(struct node **root, int val)
{   
    if ((*root)->key > val){
        (*root)->left = delnode(&((*root)->left), val);
    }
    else if ((*root)->key < val){
        (*root)->right = delnode(&((*root)->right), val);
    }
    else {
        if ((*root)->right == NULL && (*root)->left == NULL){
            struct node *temp = *root;
            free(temp);
            return NULL;
        }
        if ((*root)->right == NULL && (*root)->left != NULL){
            struct node *temp = *root;
            (*root) = NULL;
            free(temp);
            return (*root)->left;
        }
        else if ((*root)->left == NULL && (*root)->right != NULL){
            struct node *temp = *root;
            (*root) = NULL;
            free(temp);
            return (*root)->right;
        }
        else if ((*root)->left != NULL && (*root)->right != NULL){
            struct node *temp = (*root)->right;
            (*root)->key = getRightMin(temp);
            (*root)->right = delnode(&((*root)->right), (*root)->key );
            // return (*root);
        }
    }
    return *root;
    
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

void inorder(struct node *root)
{
    if (root->left != NULL){
    inorder(root->left);
    }
    printf("%d ",root->key);
    if (root->right != NULL){
    inorder(root->right);
    }
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

    root = delnode(&root,key);
    inorder(root);

    return 0;
}
