#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void levelOrder(Node* root) {
    if (root == NULL)
        return;

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];

        cout << current->data << " ";

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

int main() {
    Node* root = new Node{10, NULL, NULL};
    root->left = new Node{20, NULL, NULL};
    root->right = new Node{30, NULL, NULL};
    root->left->left = new Node{40, NULL, NULL};
    root->left->right = new Node{50, NULL, NULL};
    root->right->left = new Node{60, NULL, NULL};
    root->right->right = new Node{70, NULL, NULL};

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}
