#include <iostream>
#include <string>

using namespace std;

class Message {
public:
	string Text;
	string DeviceType;
	Message(const string& text, const string& deviceType)
		: Text(text), DeviceType(deviceType) {}
};

template <typename T>
class SLLNode {
public:
	T data;
	SLLNode* next;
	SLLNode(const T& element) : data(element), next(nullptr) {}
};

template <typename T>
class QueueSLL {
private:
	SLLNode<T>* front;
	SLLNode<T>* rear;
	int count;

public:
	QueueSLL() : front(nullptr), rear(nullptr), count(0) {}

	~QueueSLL() {
		while (!isEmpty()) {
			dequeue();
		}
	}

	int size() const {
		return count;
	}

	bool isEmpty() const {
		return count == 0;
	}

	T Front() const {
		if (isEmpty()) {
			throw runtime_error("Queue is empty");
		}
		return front->data;
	}

	T Rear() const {
		if (isEmpty()) {
			throw runtime_error("Queue is empty");
		}
		return rear->data;
	}

	T dequeue() {
		if (isEmpty()) {
			throw runtime_error("Queue is empty");
		}
		SLLNode<T>* temp = front;
		T data = front->data;
		front = front->next;
		delete temp;
		count--;
		return data;
	}

	void enqueue(const T& element) {
		SLLNode<T>* newNode = new SLLNode<T>(element);
		if (isEmpty()) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
		count++;
	}
};

int main() {
	Message inputDeviceMsgObj("Input message", "input");
	Message outputDeviceMsgObj("Output message", "output");

	QueueSLL<Message> messageQueue;

	messageQueue.enqueue(inputDeviceMsgObj);
	messageQueue.enqueue(outputDeviceMsgObj);

	cout << "Front Message: " << messageQueue.Front().Text << endl;
	cout << "Rear Message: " << messageQueue.Rear().Text << endl;

	cout << "Dequeued Message: " << messageQueue.dequeue().Text << endl;

	cout << "Queue Size: " << messageQueue.size() << endl;

	return 0;
}
