#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// index starts at size - 1 and moves backwards
Node* buildTree(int postorder[], int& index) {

    if (index < 0)
        return NULL;

    if (postorder[index] == -1) {
        index--;
        return NULL;
    }

    Node* root = new Node();
    root->data = postorder[index];
    root->left = NULL;
    root->right = NULL;
    index--;

    // Order matters: right first, then left
    root->right = buildTree(postorder, index);
    root->left  = buildTree(postorder, index);

    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Same tree as your preorder example, written in postorder with -1 for nulls
    int postorder[] = {
        -1, -1, -1, 4, -1, -1, 5, 2,
        -1, -1, 6, -1, 3, 1
    };

    int size = sizeof(postorder) / sizeof(postorder[0]);
    int index = size - 1;

    Node* root = buildTree(postorder, index);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;   // prints: 4 2 5 1 3 6

    return 0;
}