#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* topNode;
    int count;

public:
    Stack() : topNode(nullptr), count(0) {}

    int size() const {
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool top(T& element) const {
        if (isEmpty()) {
            return false;
        }
        element = topNode->data;
        return true;
    }

    void pop() {
        if (isEmpty()) {
            std::cerr << "Error: Stack is empty. Cannot pop." << std::endl;
            return;
        }
        Node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }

    void push(const T& element) {
        Node<T>* newNode = new Node<T>(element);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }
};

int main() {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Stack size: " << stack.size() << std::endl;
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    int topElement;
    if (stack.top(topElement)) {
        std::cout << "Top element: " << topElement << std::endl;
    }
    else {
        std::cout << "Stack is empty. Cannot get the top element." << std::endl;
    }

    stack.pop();
    std::cout << "Popped one element from the stack." << std::endl;

    if (stack.top(topElement)) {
        std::cout << "Top element: " << topElement << std::endl;
    }
    else {
        std::cout << "Stack is empty. Cannot get the top element." << std::endl;
    }

    return 0;
}
