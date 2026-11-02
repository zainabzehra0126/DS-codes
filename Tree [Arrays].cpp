
#include <iostream>
using namespace std;

const int SIZE = 100;
const int EMPTY = -1;

int tree[SIZE];

// Initialize the tree
void initializeTree() {
    for (int i = 0; i < SIZE; i++) {
        tree[i] = EMPTY;
    }
}

// Insert a node
void insertNode(int value) {
    // If the root is empty
    if (tree[0] == EMPTY) {
        tree[0] = value;
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        if (tree[i] == EMPTY) {
            tree[i] = value;
            return;
        }
    }

    cout << "Tree is full!" << endl;
}

// Search for a value
void searchNode(int value) {
    for (int i = 0; i < SIZE; i++) {
        if (tree[i] == value) {
            cout << value << " found at index " << i << endl;
            return;
        }
    }

    cout << value << " not found in the tree." << endl;
}

// Preorder: Root, Left, Right
void preorder(int index) {
    if (index >= SIZE || tree[index] == EMPTY)
        return;

    cout << tree[index] << " ";

    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

// Inorder: Left, Root, Right
void inorder(int index) {
    if (index >= SIZE || tree[index] == EMPTY)
        return;

    inorder(2 * index + 1);

    cout << tree[index] << " ";

    inorder(2 * index + 2);
}

// Postorder: Left, Right, Root
void postorder(int index) {
    if (index >= SIZE || tree[index] == EMPTY)
        return;

    postorder(2 * index + 1);
    postorder(2 * index + 2);

    cout << tree[index] << " ";
}

int main() {
    initializeTree();

    insertNode(10);
    insertNode(25);
    insertNode(5);
    insertNode(3);
    insertNode(12);
    insertNode(24);
    insertNode(30);

    cout << "Preorder Traversal: ";
    preorder(1);

    cout << "\nInorder Traversal: ";
    inorder(0);

    cout << "\nPostorder Traversal: ";
    postorder(0);

    cout << "\n\nSearching for 12: ";
    searchNode(12);

    cout << "Searching for 50: ";
    searchNode(50);

    return 0;
}

