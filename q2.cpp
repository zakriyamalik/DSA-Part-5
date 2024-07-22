#include <iostream>
#include <queue>

using namespace std;

class CallCenter {
private:
	queue<int> calls;
	int availableOperators;

public:
	CallCenter(int numOperators) : availableOperators(numOperators) {}

	void addCall(int callID) {
		calls.push(callID);
		cout << "Call " << callID << " added to the queue." << endl;
	}

	void assignCall() {
		if (availableOperators > 0 && !calls.empty()) {
			int callID = calls.front();
			calls.pop();
			availableOperators--;
			cout << "Operator assigned to call " << callID << "." << endl;
		}
		else {
			cout << "No available operators or no calls in the queue." << endl;
		}
	}

	void processCall() {
		if (availableOperators < 2) { // Assuming 2 operators are available
			availableOperators++;
			cout << "Call processed and operator is available now." << endl;
		}
		else {
			cout << "No calls to process or all operators are busy." << endl;
		}
	}

	void displayQueue() {
		if (calls.empty()) {
			cout << "No calls in the queue." << endl;
		}
		else {
			cout << "Current calls in the queue: ";
			queue<int> temp = calls;
			while (!temp.empty()) {
				cout << temp.front() << " ";
				temp.pop();
			}
			cout << endl;
		}
	}
};

int main() {
	CallCenter callCenter(2); // Assuming 2 operators are available
	callCenter.addCall(101);
	callCenter.addCall(102);
	callCenter.addCall(103);
	callCenter.displayQueue();
	callCenter.assignCall();
	callCenter.assignCall();
	callCenter.displayQueue();
	callCenter.processCall();
	callCenter.displayQueue();

	return 0;
}
