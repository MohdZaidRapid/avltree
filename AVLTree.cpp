#include<iostream>
using namespace std;

class Node {
public:
    int data, height;
    Node* left, * right;

    Node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node* root) {
    if (!root) {
        return 0;
    }
    return root->height = 1 + max(getHeight(root->left), getHeight(root->right));
}

int getBalance(Node* root) {
    if (!root) {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

Node* rightRotation(Node* root);
Node* leftRotation(Node* root);

Node* insert(Node* root, int key) {
    // Doesn't exist
    if (!root) {
        return new Node(key);
    }

    // Exist hai
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    else {
        return root;   //duplicate elements are not allowed
    }
    // update height 
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Balancing check

    int balance = getBalance(root);

    // Left Left case
    if (balance > 1 && key < root->left->data)
        return rightRotation(root);
    // Right Right case
    else if (balance < -1 && root->right->data < key)
        return leftRotation(root);
    // Left Right case
    else if (balance > 1 && key > root->left->data) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // Right Left case
    else if (balance < -1 && root->right->data > key) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    // No Unbalancing
    else {
        return root;
    }

}

Node* rightRotation(Node* root) {
    Node* child = root->left;
    Node* childRight = child->right;

    child->right = root;
    root->left = childRight;

    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;

}
// R R
Node* leftRotation(Node* root) {
    Node* child = root->right;
    Node* childLeft = child->left;


    child->left = root;
    root->right = childLeft;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

int main() {
    // Duplicate elements not allowed
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);
    return 0;
}
