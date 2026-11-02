#include <iostream>
using namespace std;

const int MAX = 100;

class BST {
private:
    int data[MAX];
    int leftChild[MAX];
    int rightChild[MAX];

    int root;
    int count;

    // Create a new node
    int createNode(int value) {
        data[count] = value;
        leftChild[count] = -1;
        rightChild[count] = -1;

        return count++;
    }

    // Insert a value into the BST
    int insertNode(int node, int value) {
        if (node == -1) {
            return createNode(value);
        }

        if (value < data[node]) {
            leftChild[node] = insertNode(leftChild[node], value);
        }
        else if (value > data[node]) {
            rightChild[node] = insertNode(rightChild[node], value);
        }

        return node;
    }

    // Search for a value
    bool searchNode(int node, int value) {
        if (node == -1) {
            return false;
        }

        if (data[node] == value) {
            return true;
        }

        if (value < data[node]) {
            return searchNode(leftChild[node], value);
        }

        return searchNode(rightChild[node], value);
    }

    // In-order traversal for sorted output
    void inorder(int node) {
        if (node == -1) {
            return;
        }

        inorder(leftChild[node]);
        cout << data[node] << " ";
        inorder(rightChild[node]);
    }

    // Find the smallest node in a subtree
    int findMin(int node) {
        while (leftChild[node] != -1) {
            node = leftChild[node];
        }

        return node;
    }

    // Delete a value from the BST
    int deleteNode(int node, int value) {
        if (node == -1) {
            return -1;
        }

        if (value < data[node]) {
            leftChild[node] = deleteNode(leftChild[node], value);
        }
        else if (value > data[node]) {
            rightChild[node] = deleteNode(rightChild[node], value);
        }
        else {
            // Case 1: No children
            if (leftChild[node] == -1 && rightChild[node] == -1) {
                return -1;
            }

            // Case 2: Only right child
            if (leftChild[node] == -1) {
                return rightChild[node];
            }

            // Case 2: Only left child
            if (rightChild[node] == -1) {
                return leftChild[node];
            }

            // Case 3: Two children
            // Find the in-order successor
            int successor = findMin(rightChild[node]);

            data[node] = data[successor];

            rightChild[node] = deleteNode(rightChild[node], data[successor]);
        }

        return node;
    }

public:
    BST() {
        root = -1;
        count = 0;
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

