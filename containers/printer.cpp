#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

//-- interface --
class Printer {
protected:
	std::queue<std::string> Queue;
public:
	Printer() : Queue() {};
	virtual void inQueue() = 0;
	virtual void print() = 0;
	virtual void add(std::string str) = 0;
};

class printStr : public Printer {
protected:
	std::queue<std::string> Queue;
public:
	printStr() : Printer() {};
	void print() {
		while (!Queue.empty()) {
			cout << "PRINT> " << Queue.front() << endl;
			Queue.pop();
		}
		std::cout << std::endl;
	}
	void add(std::string str) {
		Queue.push(str);
		cout << "Queued:" << "[ " << str << " ]" << endl;
 	}
	void inQueue() {
		if (Queue.empty()) {
			cout << "Queue is empty" << endl;
		} else {
		cout << "Queue size: " << Queue.size() << endl;
		cout << "Next in queue: " << Queue.front() << endl;
		cout << std::endl;
		}
	}
};

int main() {
	printStr printer;
	printer.add("Hello");
	printer.add("World");
	printer.inQueue();
	printer.print();
	printer.inQueue();
	return 0;
}