#include<stdio.h>
#include<stdlib.h>

// Defining the node structure of the BST
struct node
{
    struct node * left;
    int data;
    struct node * right;
};

// Create a new node 
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node in the BST
struct node* insert(struct node* root, int val){
    if(root == NULL){
        return createNode(val);
    }
    if(root->data > val){
        root->left = insert(root->left , val);
    } else if(root->data < val){
        root->right = insert(root->right , val);
    }
    return root;
}

// Find the inorder successor (smallest node/ minimum element in right subtree)
struct node* inorderSuccessor(struct node* root){
    struct node* curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    } 
    return curr;
}

// Delete a node from the BST
struct node* delete(struct node* root, int val){
    if(root == NULL){
        return root;
    }
    // find the node to be deleted
    if(root->data > val){
        root->left = delete(root->left , val);
    } else if(root->data < val){
        root->right = delete(root->right , val);
    } 

    else{// root->data == val
         
         // Case 1: No Child
         if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
         }

         // Case 2: One Child
         if(root->left==NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
         }
         if(root->right==NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
         }

         // Case 3: Two Children
         struct node* IS = inorderSuccessor(root->right);
         root->data = IS->data;
         root->right = delete(root->right, IS->data);
    }
    return root;
}

// Search for a element in BST
int search(struct node* root, int key){
    if(root==NULL){
        return 0;
    } else if(root->data > key){
        return search(root->left, key);
    } else if(root->data < key){
        return search(root->right, key);
    } else return 1;
}

// BST traversal: preorder
void preorder(struct node* root){
    if(root == NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
// BST traversal: inorder
void inorder(struct node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
// BST traversal: postorder
void postorder(struct node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

// Driver Code
int main() {
    struct node* root = NULL;
    int n, val;

    // Dynamic input for initial insert
    printf("Enter the number of elements you want to insert initially: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nCurrent BST:");
    printf("\nInorder: ");
    inorder(root);

    // Search a node in the BST
    int key = 0;
    printf("\nEnter the search element: ");
    scanf("%d", &key);
    if (search(root, key)) {
        printf("FOUND\n");
    } else {
        printf("NOT FOUND\n");
    }

    // Insert additional nodes
    root = insert(root, 65);
    root = insert(root, 45);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 85);

    printf("\nCurrent BST:");
    printf("\nInorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    // Loop for deleting nodes
    char choice = 'y';
    while (choice == 'y') {
        printf("\nEnter the element to delete: ");
        scanf("%d", &key);

        // Check if the element exists before attempting deletion
        if (!search(root, key)) {
            printf("Element %d not found in the tree.\n", key);
        } else {
            root = delete(root, key);
            printf("\nInorder after deletion: ");
            inorder(root);
        }

        // Check if the tree is empty
        if (root == NULL) {
            printf("\nTree is now empty.\n");
            break;
        }

        printf("\nDo you want to delete another element? (y/n): ");
        scanf(" %c", &choice);

        // Input validation to ensure correct choices are made
        while (choice != 'y' && choice != 'n') {
            printf("Invalid input. Please enter 'y' or 'n': ");
            scanf(" %c", &choice);
        }
    }

    // Final traversal (if tree is not empty)
    if (root != NULL) {
        printf("\nFinal BST:");
        printf("\nInorder: ");
        inorder(root);

        printf("\nPreorder: ");
        preorder(root);

        printf("\nPostorder: ");
        postorder(root);
    } else {
        printf("\nTree is empty. No traversals to display.\n");
    }

    return 0;
}
