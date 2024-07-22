#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}

    void insertHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    bool isEqualRec(Node* current1, Node* current2) {
        if (current1 == nullptr && current2 == nullptr) {
            return true;
        }
        if (current1 == nullptr || current2 == nullptr || current1->data != current2->data) {
            return false;
        }
        return isEqualRec(current1->next, current2->next);
    }

    bool isEqual(const List& obj) {
        return isEqualRec(head, obj.head);
    }

    void deepCopyRec(Node* source, Node*& dest) {
        if (source == nullptr) {
            dest = nullptr;
            return;
        }
        dest = new Node(source->data);
        deepCopyRec(source->next, dest->next);
    }

    void deepCopy(const List& obj) {
        deepCopyRec(obj.head, head);
    }

    void recursiveReverseRec(Node* current, Node* prev) {
        if (current == nullptr) {
            head = prev;
            return;
        }
        Node* nextNode = current->next;
        current->next = prev;
        recursiveReverseRec(nextNode, current);
    }

    void recursiveReverse() {
        recursiveReverseRec(head, nullptr);
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    List list1, list2, list3;

    list1.insertHead(5);
    list1.insertHead(7);
    list1.insertHead(9);
    list1.insertHead(10);

    list2.deepCopy(list1);
    list2.printList();

    list3.insertHead(5);
    list3.insertHead(7);
    list3.insertHead(9);
    list3.insertHead(10);
    list3.recursiveReverse();
    list3.printList();

    if (list2.isEqual(list1)) {
        std::cout << "List 2 and List 1 are equal." << std::endl;
    }
    else {
        std::cout << "List 2 and List 1 are not equal." << std::endl;
    }

    if (list2.isEqual(list3)) {
        std::cout << "List 2 and List 3 are equal." << std::endl;
    }
    else {
        std::cout << "List 2 and List 3 are not equal." << std::endl;
    }

    return 0;
}
