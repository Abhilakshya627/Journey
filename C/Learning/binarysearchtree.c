#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *l;
    int data;
    struct node *r;
} bt;

bt *createNode(int x) {
    bt *newNode = (bt *)malloc(sizeof(bt));
    newNode->data = x;
    newNode->l = NULL;
    newNode->r = NULL;
    return newNode;
}

void insert(bt **root, int x) {
    if (*root == NULL) {
        *root = createNode(x);
        return;
    }
    if (x < (*root)->data) {
        insert(&((*root)->l), x);
    } else {
        insert(&((*root)->r), x);
    }
}

bt *findMin(bt *root) {
    while (root->l != NULL) root = root->l;
    return root;
}

bt *deleteNode(bt *root, int x) {
    if (root == NULL) return root;
    if (x < root->data) {
        root->l = deleteNode(root->l, x);
    } else if (x > root->data) {
        root->r = deleteNode(root->r, x);
    } else {
        // Node with only one child or no child
        if (root->l == NULL) {
            bt *temp = root->r;
            free(root);
            return temp;
        } else if (root->r == NULL) {
            bt *temp = root->l;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        bt *temp = findMin(root->r);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->r = deleteNode(root->r, temp->data);
    }
    return root;
}

void inorder(bt *root) {
    if (root != NULL) {
        inorder(root->l);
        printf("%d ", root->data);
        inorder(root->r);
    }
}

int main() {
    bt *root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 0;
}