#include<iostream>
using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head;
public:
    List() {
        head = nullptr;
    }

   void insert_at_start(T data) {
        Node* newnode = new Node(data);
        if (!head) {
            head = newnode;
            newnode->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newnode->next = head;
            head = newnode;
            temp->next = head;
        }
    }

    void insert_at_the_end(T data) {
        Node* newnode = new Node(data);
        if (!head) {
            head = newnode;
            newnode->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }
    }

    bool addAfter(T data, T item) {
        if (!head) {
            return false;
        }
        Node* temp = head;
        do {
            if (temp->data == item) {
                Node* newnode = new Node(data);
                newnode->next = temp->next;
                temp->next = newnode;
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    bool deleteNode(T key) {
        if (!head) {
            return false;
        }
        Node* temp = head;
        Node* prev = nullptr;
        do {
            if (temp->data == key) {
                if (temp == head) {
                    Node* lastNode = head;
                    while (lastNode->next != head) {
                        lastNode = lastNode->next;
                    }
                    head = head->next;
                    lastNode->next = head;
                }
                else {
                    prev->next = temp->next;
                }
                delete temp;
                return true;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        return false;
    }
};

int main() {
    List<int> mylist;
    mylist.insert_at_start(4);
    mylist.insert_at_the_end(5);
    mylist.addAfter(3, 4);
    mylist.deleteNode(4);

    return 0;
}
