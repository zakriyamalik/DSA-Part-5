#include <iostream>

using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value)
        {
            data = value;
            next = nullptr;
        }
    };

    Node* head;

public:
    List()
    {
        head = nullptr;
    }
    void insertAtStart(const T& element) {
        Node* newNode = new Node(element);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(const T& element) {
        Node* newNode = new Node(element);
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
    void deleteAtStart() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteAtEnd() {
        if (!head) {
            return; 
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }
    void display() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printReverse() const {
        printReverseRecursive(head);
        cout << endl;
    }
    int size() const {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    T returnMiddle() const {
        if (!head) {
            throw runtime_error("List is empty");
        }

        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

    // Function to check if the list is empty
    bool isEmpty() const {
        return head == nullptr;
    }

    T findMax() const {
        if (!head) {
            throw runtime_error("List is empty");
        }

        T max = head->data;
        Node* current = head->next;
        while (current) {
            if (current->data > max) {
                max = current->data;
            }
            current = current->next;
        }

        return max;
    }

  
    void insertAfter(const T& val, const T& key) {
        Node* current = head;

        while (current) {
            if (current->data == val) {
                Node* newNode = new Node(key);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        insertAtEnd(key);
    }
    void insertBefore(const T& val, const T& key) {
        if (!head) {
            insertAtStart(key);
            return;
        }

        if (head->data == val) {
            insertAtStart(key);
            return;
        }

        Node* current = head;

        while (current->next) {
            if (current->next->data == val) {
                Node* newNode = new Node(key);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }

        insertAtEnd(key);
    }
    void deleteDuplicates() {
        Node* current = head;

        while (current != nullptr) {
            Node* runner = current;

            while (runner->next != nullptr) {
                if (runner->next->data == current->data) {
                    Node* duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate;
                }
                else {
                    runner = runner->next;
                }
            }

            current = current->next;
        }
    }
};

int main() {
    List<int> myList;

    myList.insertAtStart(3);
    myList.insertAtStart(2);
    myList.insertAtStart(1);

    cout << "List: ";
    myList.display();

    myList.insertAtEnd(4);
    myList.insertAtEnd(5);

    cout << "List after inserting at end: ";
    myList.display();

    myList.deleteAtStart();
    cout << "List after deleting from start: ";
    myList.display();

    myList.deleteAtEnd();
    cout << "List after deleting from end: ";
    myList.display();

    cout << "List in reverse: ";
    myList.printReverse();

    cout << "Size of the list: " << myList.size() << endl;

    cout << "Middle element of the list: " << myList.returnMiddle() << endl;

    cout << "Is the list empty? " << (myList.isEmpty() ? "Yes" : "No") << endl;

    myList.insertAfter(2, 6);
    cout << "List after inserting 6 after the first occurrence of 2: ";
    myList.display();

    myList.insertBefore(4, 7);
    cout << "List after inserting 7 before the first occurrence of 4: ";
    myList.display();

    myList.insertAfter(8, 9); 
    cout << "List after inserting 9 after the first occurrence of 8 (not found): ";
    myList.display();

    myList.deleteDuplicates();
    cout << "List after deleting duplicates: ";
    myList.display();

    cout << "Maximum element in the list: " << myList.findMax() << endl;

    return 0;
}
