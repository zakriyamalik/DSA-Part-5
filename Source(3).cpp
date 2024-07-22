#include <iostream>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    bool insertHelper(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
            return true;
        }

        if (value < node->data) {
            return insertHelper(node->left, value);
        }
        else if (value > node->data) {
            return insertHelper(node->right, value);
        }
        else {
            return false;
        }
    }

    void inorderPrintHelper(const Node* node) const {
        if (node) {
            inorderPrintHelper(node->left);
            std::cout << node->data << " ";
            inorderPrintHelper(node->right);
        }
    }
    void levelorderPrintHelper(const Node* node) const {
        if (node == nullptr) return;

        std::queue<const Node*> q;
        q.push(node);

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                const Node* current = q.front();
                q.pop();
                std::cout << current->data << " ";

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }
    }

    Node* searchHelper(Node* node, int key) {
        if (node == nullptr || node->data == key) {
            return node;
        }

        if (key < node->data) {
            return searchHelper(node->left, key);
        }
        else {
            return searchHelper(node->right, key);
        }
    }

   int countNodesHelper(const Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
    }

    // Helper function for leafCount
    int leafCountHelper(const Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }
        return leafCountHelper(node->left) + leafCountHelper(node->right);
    }

    // Helper function for destructor
    void deleteTree(Node* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    BST() : root(nullptr) {}

    bool insert(int value) {
        return insertHelper(root, value);
    }

    // Copy constructor
    BST(const BST& other) {
        root = nullptr;
        copyHelper(other.root, root);
    }

    // Copy helper function
    void copyHelper(Node* const& source, Node*& dest) {
        if (source) {
            dest = new Node(source->data);
            copyHelper(source->left, dest->left);
            copyHelper(source->right, dest->right);
        }
    }

    void inorderPrint() const {
        inorderPrintHelper(root);
        std::cout << std::endl;
    }

    void levelorderPrint() const {
        levelorderPrintHelper(root);
    }

    Node* search(int key) {
        return searchHelper(root, key);
    }

    int countNodes() const {
        return countNodesHelper(root);
    }

    int leafCount() const {
        return leafCountHelper(root);
    }

    ~BST() {
        deleteTree(root);
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "In-order traversal: ";
    tree.inorderPrint();

    std::cout << "Level-order traversal:\n";
    tree.levelorderPrint();

    std::cout << "Number of nodes in the tree: " << tree.countNodes() << std::endl;
    std::cout << "Number of leaf nodes in the tree: " << tree.leafCount() << std::endl;

    Node* searchResult = tree.search(40);
    if (searchResult) {
        std::cout << "Found: " << searchResult->data << std::endl;
    }
    else {
        std::cout << "Not found." << std::endl;
    }

    return 0;
}
