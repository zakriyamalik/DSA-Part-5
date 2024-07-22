#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* dummyHead;
    Node* dummyTail;

public:
    DoublyLinkedList() {
        dummyHead = new Node(T());
        dummyTail = new Node(T());
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    // Insert at the start of the doubly linked list
    void insertAtStart(const T element) {
        Node* newNode = new Node(element);
        newNode->next = dummyHead->next;
        newNode->prev = dummyHead;
        dummyHead->next->prev = newNode;
        dummyHead->next = newNode;
    }

    // Insert at the end of the doubly linked list
    void insertAtEnd(const T element) {
        Node* newNode = new Node(element);
        newNode->prev = dummyTail->prev;
        newNode->next = dummyTail;
        dummyTail->prev->next = newNode;
        dummyTail->prev = newNode;
    }

    // Delete from the start of the doubly linked list
    void deleteAtStart() {
        if (dummyHead->next != dummyTail) {
            Node* temp = dummyHead->next;
            dummyHead->next = temp->next;
            temp->next->prev = dummyHead;
            delete temp;
        }
    }

    // Delete from the end of the doubly linked list
    void deleteAtEnd() {
        if (dummyTail->prev != dummyHead) {
            Node* temp = dummyTail->prev;
            dummyTail->prev = temp->prev;
            temp->prev->next = dummyTail;
            delete temp;
        }
    }

    // Print the doubly linked list
    void print() const {
        Node* current = dummyHead->next;
        while (current != dummyTail) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Reverse all elements of the doubly linked list
    void reverse() {
        Node* current = dummyHead->next;
        Node* prev = nullptr;
        while (current != dummyTail) {
            Node* next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
        }
        dummyTail->prev = dummyHead->next;
        dummyHead->next = prev;
    }

    // Remove all duplicate values from the doubly linked list
    void removeDuplicates() {
        Node* current = dummyHead->next;
        while (current != dummyTail) {
            Node* runner = current->next;
            while (runner != dummyTail) {
                if (current->data == runner->data) {
                    Node* temp = runner;
                    runner->prev->next = runner->next;
                    runner->next->prev = runner->prev;
                    runner = runner->next;
                    delete temp;
                }
                else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    // Insert value v1 before value v2
    bool insertBefore(const T v1, const T v2) {
        Node* current = dummyHead->next;
        while (current != dummyTail) {
            if (current->data == v2) {
                Node* newNode = new Node(v1);
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* current = dummyHead;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList<int> myList;

    myList.insertAtEnd(7);
    myList.insertAtEnd(9);
    myList.insertAtStart(9);
    myList.insertAtEnd(10);
    myList.insertAtEnd(9);

    std::cout << "Original List: ";
    myList.print();

    myList.removeDuplicates();
    std::cout << "List after removing duplicates: ";
    myList.print();

    myList.insertBefore(6, 11);
    std::cout << "List after inserting 6 before 11: ";
    myList.print();

    myList.reverse();
    std::cout << "Reversed List: ";
    myList.print();

    return 0;
}
