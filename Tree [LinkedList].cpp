#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node level by level
void insertNode(Node*& root, int value) {
    Node* newNode = createNode(value);

    // If the tree is empty
    if (root == NULL) {
        root = newNode;
        return;
    }

    // Use an array as a simple queue
    Node* queue[100];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* temp = queue[front++];

        // Check the left child
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        }
        else {
            queue[rear++] = temp->left;
        }

        // Check the right child
        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        }
        else {
            queue[rear++] = temp->right;
        }
    }
}

// Preorder: Root, Left, Right
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder: Left, Root, Right
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder: Left, Right, Root
void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    insertNode(root, 10);
    insertNode(root, 25);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 12);
    insertNode(root, 24);
    insertNode(root, 30);

    cout << "Preorder Traversal: ";
    preorder(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    cout << endl;

    return 0;
}

