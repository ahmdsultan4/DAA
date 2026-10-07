#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* build_binary_tree() {
    int val;
    cout << "Enter root value (-1 for no node): ";
    cin >> val;
    if (val == -1) return nullptr;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int leftVal, rightVal;
        cout << "Enter left child of " << curr->data << " (-1 for none): ";
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->data << " (-1 for none): ";
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}

void level_order(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    cout << "Level Order Traversal:";
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << " " << curr->data;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << endl;
}

int main() {
    Node* root = build_binary_tree();
    level_order(root);
    return 0;
}