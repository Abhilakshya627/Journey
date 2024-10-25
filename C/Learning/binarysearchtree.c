#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *l;
    int data;
    struct node *r;
}bt;

bt *createNode(int x){
    bt *newNode=(bt*)malloc(sizeof(bt));
    newNode->data=x;
    newNode->l=NULL;
    newNode->r=NULL;
    return newNode;
}

void insert(bt **root, int x){
    if(*root==NULL){
        *root=createNode(x);
        return;
    }
    if(x<(*root)->data)
        insert(&(*root)->l,x);
    else
        insert(&(*root)->r,x);
}

void displayInOrder(bt *root){
    if(root==NULL){
        return;
    }
    displayInOrder(root->l);
    printf("%d ",root->data);
    displayInOrder(root->r);
}

void displayPreOrder(bt *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    displayPreOrder(root->l);
    displayPreOrder(root->r);
}

void displayPostOrder(bt *root){
    if(root==NULL){
        return;
    }
    displayPostOrder(root->l);
    displayPostOrder(root->r);
    printf("%d ",root->data);
}

int main(){
    bt *root=NULL;
    insert(&root,10);
    insert(&root,5);
    insert(&root,15);
    insert(&root,3);
    insert(&root,7);
    insert(&root,12);
    insert(&root,18);
    printf("InOrder: ");
    displayInOrder(root);
    printf("\nPreOrder: ");
    displayPreOrder(root);
    printf("\nPostOrder: ");
    displayPostOrder(root);
    return 0;
}