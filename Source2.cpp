#include <iostream>
#include<queue>
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

class LinkedListBinaryTree {
private:
    Node* root;

    // Helper function to perform Inorder Traversal
    void inorderTraversal(Node* node) {
        if (node) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    // Helper function to perform Preorder Traversal
    void preorderTraversal(Node* node) {
        if (node) {
            std::cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    // Helper function to perform Postorder Traversal
    void postorderTraversal(Node* node) {
        if (node) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            std::cout << node->data << " ";
        }
    }

public:
    LinkedListBinaryTree() : root(nullptr) {}

    void insert(char value) {
        if (root == nullptr) {
            root = new Node(value);
        }
        else {
          std::queue<Node*> nodesQueue;
            nodesQueue.push(root);

            while (!nodesQueue.empty()) {
                Node* current = nodesQueue.front();
                nodesQueue.pop();

                if (current->left == nullptr) {
                    current->left = new Node(value);
                    break;
                }
                else {
                    nodesQueue.push(current->left);
                }

                if (current->right == nullptr) {
                    current->right = new Node(value);
                    break;
                }
                else {
                    nodesQueue.push(current->right);
                }
            }
        }
    }

    void inorderTraversal() {
        std::cout << "Inorder Traversal: ";
        inorderTraversal(root);
        std::cout << std::endl;
    }

    void preorderTraversal() {
        std::cout << "Preorder Traversal: ";
        preorderTraversal(root);
        std::cout << std::endl;
    }

    void postorderTraversal() {
        std::cout << "Postorder Traversal: ";
        postorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    LinkedListBinaryTree tree;

    tree.insert('A');
    tree.insert('B');
    tree.insert('C');
    tree.insert('D');
    tree.insert('E');
    tree.insert('F');
    tree.insert('G');

    tree.inorderTraversal();
    tree.preorderTraversal();
    tree.postorderTraversal();

    return 0;
}
