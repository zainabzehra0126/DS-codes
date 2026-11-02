#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node*& root, int value) {
    Node* newNode = createNode(value);

    if (root == NULL) {
        root = newNode;
        return;
    }

    Node* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        }
        else {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        }
        else {
            queue[rear++] = temp->right;
        }
    }
}

// ---------- UPDATE ----------
// Replaces the first node holding oldVal. Returns true if found.
bool updateNode(Node* root, int oldVal, int newVal) {
    if (root == NULL)
        return false;

    if (root->data == oldVal) {
        root->data = newVal;
        return true;
    }

    return updateNode(root->left, oldVal, newVal) ||
           updateNode(root->right, oldVal, newVal);
}

// ---------- DELETE ----------
// 1. find the node holding key
// 2. find the deepest rightmost node (last node in level order)
// 3. copy its data into the target
// 4. detach and free the deepest node

void deleteNode(Node*& root, int key) {
    if (root == NULL) {
        cout << "Tree is empty\n";
        return;
    }

    Node* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;

    Node* target = NULL;       // node that holds the key
    Node* last = root;         // deepest rightmost node so far
    Node* lastParent = NULL;   // parent of 'last'
    bool lastIsLeft = false;

    while (front < rear) {
        Node* temp = queue[front++];

        if (temp->data == key && target == NULL)
            target = temp;

        if (temp->left != NULL) {
            queue[rear++] = temp->left;
            last = temp->left;
            lastParent = temp;
            lastIsLeft = true;
        }
        if (temp->right != NULL) {
            queue[rear++] = temp->right;
            last = temp->right;
            lastParent = temp;
            lastIsLeft = false;
        }
    }

    if (target == NULL) {
        cout << key << " not found\n";
        return;
    }

    target->data = last->data;      // overwrite with deepest node's value

    if (lastParent == NULL) {       // tree had only the root
        delete root;
        root = NULL;
    }
    else {
        if (lastIsLeft)
            lastParent->left = NULL;
        else
            lastParent->right = NULL;
        delete last;
    }
}


void freeTree(Node* root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void showAll(Node* root) {
    cout << "Preorder:  "; preorder(root);
    cout << "\nInorder:   "; inorder(root);
    cout << "\nPostorder: "; postorder(root);
    cout << "\n\n";
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

    cout << "Original tree\n";
    showAll(root);
    // Inorder: 3 25 12 10 24 5 30

    if (updateNode(root, 24, 99))
        cout << "Updated 24 -> 99\n";
    showAll(root);
    // Inorder: 3 25 12 10 99 5 30

    deleteNode(root, 25);           // 30 (deepest rightmost) replaces 25
    cout << "After deleting 25\n";
    showAll(root);
    // Inorder: 3 30 12 10 99 5

    deleteNode(root, 10);           // deleting the root also works
    cout << "After deleting 10 (root)\n";
    showAll(root);
    // Inorder: 3 30 12 99 5

    deleteNode(root, 100);          // prints "100 not found"

    freeTree(root);
    return 0;
}