#include <iostream>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool deleteNode(Node*& head, int data) {
    if (!head) {
        return false;
    }

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
    while (current->next) {
        if (current->next->data == data) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }
        current = current->next;
    }

    return false;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    srand(time(0)); 

    Node* head = nullptr;
   const int n = 10; 
    int elements[n];

    for (int i = 0; i < n; i++) {
        elements[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        int randomIndex = rand() % (n - i) + i;
        swap(elements[i], elements[randomIndex]);
        insertAtEnd(head, elements[i]);
    }

    cout << "Single Link List:" << endl;
    printList(head);
    for (int i = 0; i < 4; i++) {
        int randomValue = rand() % n + 1;
        if (deleteNode(head, randomValue)) {
            cout << "Deleted: " << randomValue << endl;
        }
    }

    cout << "Single Link List After Deletion:" << endl;
    printList(head);
    cout << "Missing elements:" << endl;
    for (int i = 1; i <= n; i++) {
        if (!deleteNode(head, i)) {
            cout << i << "->";
        }
    }
    cout << "nullptr" << endl;

    return 0;
}
