
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

class BST {
private:
    Node* root;

    // Insert a new value into the BST
    Node* insertNode(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    // Search for a value
    bool searchNode(Node* node, int value) {
        if (node == NULL) {
            return false;
        }

        if (node->data == value) {
            return true;
        }

        if (value < node->data) {
            return searchNode(node->left, value);
        }

        return searchNode(node->right, value);
    }

    // Display values in ascending order
    void inorder(Node* node) {
        if (node == NULL) {
            return;
        }

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Find the smallest value in a subtree
    Node* findMin(Node* node) {
        while (node != NULL && node->left != NULL) {
            node = node->left;
        }

        return node;
    }

    // Delete a value from the BST
    Node* deleteNode(Node* node, int value) {
        if (node == NULL) {
            return NULL;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        }
        else {
            // Case 1: No child
            if (node->left == NULL &&
                node->right == NULL) {
                delete node;
                return NULL;
            }

            // Case 2: Only right child
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // Case 2: Only left child
            if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            // Replace with the in-order successor
            Node* temp = findMin(node->right);

            node->data = temp->data;

            node->right = deleteNode(
                node->right, temp->data
            );
        }

        return node;
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    bool search(int value) {
        return searchNode(root, value);
    }

    void sort() {
        inorder(root);
        cout << endl;
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }
};

int main() {
    BST tree;

    int values[] = {
        16, 5, 7, 20, 3, 11, 4, 18, 48, 56, 36
    };

    int n = sizeof(values) / sizeof(values[0]);

    // 1. Build the BST
    for (int i = 0; i < n; i++) {
        tree.insert(values[i]);
    }

    cout << "Sorted values: ";
    tree.sort();

    // 2. Search for 11
    int key = 11;

    if (tree.search(key)) {
        cout << key << " found in the BST." << endl;
    }
    else {
        cout << key << " not found in the BST." << endl;
    }

    // 3. Insert 13
    tree.insert(13);

    cout << "After inserting 13: ";
    tree.sort();

    // 4. Delete 20
    tree.remove(20);

    cout << "After deleting 20: ";
    tree.sort();

    return 0;
}

