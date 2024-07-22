#include <iostream>
using namespace std;
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
    class iterator {
    private:
        Node* current;

    public:
        iterator(Node* node) : current(node) {}

        iterator& operator++() {
            current = current->next;
            return *this;
        }
        iterator& operator--() {
            current = current->prev;
            return *this;
        }
        T& operator*() {
            return current->data;
        }

        bool operator==(const iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }
    };
    void insertAtEnd(const T element) {
        Node* newNode = new Node(element);
        newNode->prev = dummyTail->prev;
        newNode->next = dummyTail;
        dummyTail->prev->next = newNode;
        dummyTail->prev = newNode;
    }
    DoublyLinkedList() {
        dummyHead = new Node(T());
        dummyTail = new Node(T());
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

   
    iterator begin() {
        return iterator(dummyHead->next);
    }

    iterator end() {
        return iterator(dummyTail);
    }

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

    myList.insertAtEnd(1);
    myList.insertAtEnd(2);
    myList.insertAtEnd(3);

    cout << "Printing the list backward using the iterator: ";
    for (DoublyLinkedList<int>::iterator it = myList.end(); it != myList.begin(); --it) {
       cout << *it << " ";
    }

    cout << *myList.begin() << " ";

   cout << endl;

    return 0;
}
