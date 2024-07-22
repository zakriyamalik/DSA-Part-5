#include <iostream>
using namespace std;

class Set {
    struct Node {
        int el;
        Node* next;
        Node(int val) : el(val), next(nullptr) {}
    } *head, * tail;
    int count;

public:
    Set() : head(nullptr), tail(nullptr), count(0) {}

    Set(const Set& obj) : head(nullptr), tail(nullptr), count(0) {
        Node* current = obj.head;
        while (current) {
            addElementInOrder(current->el);
            current = current->next;
        }
    }

    ~Set() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isMember(int x) {
        Node* current = head;
        while (current) {
            if (current->el == x) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool operator==(const Set& obj) {
        if (count != obj.count) {
            return false;
        }

        Node* current1 = head;
        Node* current2 = obj.head;

        while (current1 && current2) {
            if (current1->el != current2->el) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }

        return true;
    }

    void addElementInOrder(int x) {
        if (!isMember(x)) {
            Node* newNode = new Node(x);
            if (!head) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
            count++;
        }
    }

    void eraseElement(int x) {
        Node* current = head;
        Node* prev = nullptr;
        while (current) {
            if (current->el == x) {
                if (prev) {
                    prev->next = current->next;
                }
                else {
                    head = current->next;
                }
                delete current;
                count--;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void printSet() {
        cout << "{";
        Node* current = head;
        while (current) {
            cout << current->el;
            if (current->next) {
                cout << ", ";
            }
            current = current->next;
        }
        cout << "}" << endl;
    }

    Set operator+(const Set& obj) {
        Set result = *this; 
        Node* current = obj.head;
        while (current) {
            result.addElementInOrder(current->el);
            current = current->next;
        }
        return result;
    }
};

int main() {
    Set s;
    s.addElementInOrder(3);
    s.addElementInOrder(4);
    s.addElementInOrder(3);
    s.addElementInOrder(1);
    s.addElementInOrder(2);
    s.eraseElement(3);
    cout << "3 is a member of Set s: " << s.isMember(3) << endl;
    s.printSet();

    Set t;
    t.addElementInOrder(9);
    t.addElementInOrder(4);
    t.addElementInOrder(2);
    t.printSet(); 

    bool flag = s == t;
    cout << "Are set t and s equivalent: " << flag << endl;

    Set q = s + t;
    cout << "Set q (s + t): ";
    q.printSet();

    return 0;
}
