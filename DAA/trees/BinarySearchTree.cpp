#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << " " << root->data;
    inorder(root->right);
}

int main() {
    int size, val;
    cout << "Enter the number of elements: ";
    cin >> size;
    
    Node* root = nullptr;
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> val;
        root = insert(root, val);
    }
    
    cout << "In-order Traversal of BST:";
    inorder(root);
    cout << endl;
    
    return 0;
}