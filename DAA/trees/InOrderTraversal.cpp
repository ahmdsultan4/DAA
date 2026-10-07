#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* build_tree() {
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

void in_order(Node* root) {
    if (!root) return;
    in_order(root->left);
    cout << " " << root->data;
    in_order(root->right);
}

int main() {
    Node* root = build_tree();
    cout << "In-Order Traversal:";
    in_order(root);
    cout << endl;
    return 0;
}