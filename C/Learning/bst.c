#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the BST
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new key in the BST using double pointers
void insert(struct Node** root, int key) {
    // If the tree is empty, create a new node
    if (*root == NULL) {
        *root = newNode(key);
        return;
    }

    // Otherwise, recur down the tree
    if (key < (*root)->key)
        insert(&((*root)->left), key);
    else if (key > (*root)->key)
        insert(&((*root)->right), key);
}

// Function to search a given key in the BST using double pointers
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (key > root->key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to find the minimum value node in the BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a key from the BST using double pointers
void deleteNode(struct Node** root, int key) {
    // Base case
    if (*root == NULL) return;

    // Recur down the tree
    if (key < (*root)->key)
        deleteNode(&((*root)->left), key);
    else if (key > (*root)->key)
        deleteNode(&((*root)->right), key);
    else {
        // Node with only one child or no child
        if ((*root)->left == NULL) {
            struct Node* temp = (*root)->right;
            free(*root);
            *root = temp; // Update the pointer to the new subtree
        } else if ((*root)->right == NULL) {
            struct Node* temp = (*root)->left;
            free(*root);
            *root = temp; // Update the pointer to the new subtree
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            struct Node* temp = minValueNode((*root)->right);
            (*root)->key = temp->key; // Copy the inorder successor's content to this node
            deleteNode(&((*root)->right), temp->key); // Delete the inorder successor
        }
    }
}

// Function for in-order traversal of the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Main function to demonstrate the BST operations
int main() {
    struct Node* root = NULL;

    // Insert nodes
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("In-order traversal of the BST: \n");
    inorder(root);
    printf("\n");

    // Search for a key
    int key = 40;
    struct Node* foundNode = search(root, key);
    if (foundNode != NULL) {
        printf("Key %d found in the BST.\n", key);
    } else {
        printf("Key %d not found in the BST.\n", key);
    }

    // Delete a key
    printf("Deleting key 20...\n");
    deleteNode(&root, 20);
    printf("In-order traversal after deleting 20: \n");
    inorder(root);
    printf("\n");

    printf("Deleting key 30...\n");
    deleteNode(&root, 30);
    printf("In-order traversal after deleting 30: \n");
    inorder(root);
    printf("\n");
}