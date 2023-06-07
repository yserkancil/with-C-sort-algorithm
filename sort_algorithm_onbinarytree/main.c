#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Binary search tree node stucture
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// creates a new nodes
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Creates the sorted array as a binary search tree
struct Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    // Sets the middle element and creates a new node
    int mid = (start + end) / 2;
    struct Node* root = newNode(arr[mid]);

    // Creates the left subtree
    root->left = sortedArrayToBST(arr, start, mid - 1);

    // Creates the right subtree
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Inorder navigation
void sort_acordingtoBST(struct Node* node) {
    if (node == NULL)
        return;

    sort_acordingtoBST(node->left);
    printf("%d ", node->data);
    sort_acordingtoBST(node->right);
}
void sirala(int arr[],int n){
      int temp,i,j;
      for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void applyDFS(struct Node* node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    applyDFS(node->left);

    // then recur on right subtree
    applyDFS(node->right);

    // now deal with the node
    printf("%d ", node->data);
}
//after from here for BFS algorithm
void printCurrentLevel(struct Node* root, int level);
int height(struct Node* node);
struct Node* newNode(int data);


void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

void printCurrentLevel(struct Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height(struct Node* node)
{
    if (node == NULL)
        return 0;
    else {

        // Compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);

        // Use the larger one
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}


int main() {
   int i,arr[100];
   srand(time(NULL));
   for(i=0;i<100;i++){
       arr[i]=rand()%100;
   }
    //int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5, 6, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    sirala(arr,n);
    struct Node* root = sortedArrayToBST(arr, 0, n - 1);

    printf("Binary Search Tree\n");
    sort_acordingtoBST(root);
    printf("\n");

    printf("\nPostorder DFS traversal of binary tree is \n");
    applyDFS(root);
    //printf("\n\nroot::::%d",root);

    printf("Level Order traversal of binary tree is for BFS \n");
    printLevelOrder(root);


    return 0;
}
