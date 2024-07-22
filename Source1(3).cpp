#include <iostream>
#include <queue>

class ArrayBinaryTree {
private:
    char* tree;
    int arraySize;

public:
    ArrayBinaryTree(int size) {
        tree = new char[size];
        arraySize = size;
        for (int i = 0; i < size; ++i) {
            tree[i] = ' ';
        }
    }

    void insert(char data, int index) {
        if (index < arraySize) {
            tree[index] = data;
        }
        else {
            std::cout << "Index out of bounds." << std::endl;
        }
    }

    void breadthFirstTraversal() {
        std::cout << "Breadth-first order Tree Traversal" << std::endl;
        for (int i = 0; i < arraySize; ++i) {
            if (tree[i] != ' ') {
                std::cout << tree[i] << " ";
            }
        }
        std::cout << std::endl;
    }

    bool isFull() {
        for (int i = 0; i < arraySize; ++i) {
            if (tree[i] == ' ') {
                return false;
            }
        }
        return true;
    }

    ~ArrayBinaryTree() {
        delete[] tree;
    }
};

int main() {
    // Create an array-based binary tree
    ArrayBinaryTree binaryTree(10);

    // Insert elements into the tree
    binaryTree.insert('A', 0);
    binaryTree.insert('B', 1);
    binaryTree.insert('C', 2);
    binaryTree.insert('D', 3);
    binaryTree.insert('E', 4);
    binaryTree.insert('F', 5);
    binaryTree.insert('G', 6);

    binaryTree.breadthFirstTraversal();

    std::cout << "Checking if tree is full." << std::endl;
    if (binaryTree.isFull()) {
        std::cout << "Yes, the tree is full." << std::endl;
    }
    else {
        std::cout << "No, the tree is not full." << std::endl;
    }

    return 0;
}
