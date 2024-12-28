#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* Left;
    Node* Right;

    // Constructor
    Node(int data) {
        this->data = data;
        Left = nullptr;
        Right = nullptr;
    }
    
};

class BST {
public:
    Node* root;

    // Constructor
    BST() {
        root = nullptr;
    }

    // Public insert function
    void insert(int data) {
        root = insertRec(root, data);
    }

    // Recursive insert helper function
    Node* insertRec(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->Left = insertRec(node->Left, data);
        } else if (data > node->data) {
            node->Right = insertRec(node->Right, data);
        }
        return node;
    }

    // Public inorder function
    void inorder() {
        inorderRec(root);
    }

    // Recursive inorder helper function
    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->Left);
            cout << node->data << " ";
            inorderRec(node->Right);
        }
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal of the given tree: ";
    tree.inorder();

    return 0;
}
