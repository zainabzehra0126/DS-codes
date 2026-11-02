#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Find the deepest rightmost node and delete it
void deleteDeepest(Node* root, Node* target) {
    if (root == NULL)
        return;

    if (root->left == target) {
        root->left = NULL;
        delete target;
        return;
    }

    if (root->right == target) {
        root->right = NULL;
        delete target;
        return;
    }

    deleteDeepest(root->left, target);
    deleteDeepest(root->right, target);
}

// Delete a node with the given value
void deleteNode(Node* root, int value) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        if (root->data == value) {
            cout << "Root is the only node. Handle root deletion separately.\n";
        }
        return;
    }

    Node* target = NULL;
    Node* deepest = NULL;

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];

        if (current->data == value && target == NULL)
            target = current;

        deepest = current;

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }

    if (target == NULL) {
        cout << "Value not found.\n";
        return;
    }

    int deepestValue = deepest->data;
    target->data = deepestValue;
    deleteDeepest(root, deepest);

    cout << "Node deleted successfully.\n";
}
