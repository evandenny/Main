#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <tuple>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

struct counter {
	int count = 0;
	string first, last, full;
	pair<int, string> personToQueue;
	tuple<int, string, string> pieces;
	deque<pair<int, string>> Queue;
	stack<pair<int, string>> StackFULL;
	stack<tuple<int, string, string>> Stack12;
	void setTuple(string first, string last, int _count) {
		auto t = make_tuple(count, first, last);
		std::swap(t, pieces);
	}
	void createPerson() {
		cout << "[ENTER YOUR FIRST NAME]>-";
		getline(cin, first);
		cout << "[ENTER YOUR LAST NAME]>-";
		getline(cin, last);
		cout << "Queuing person..." << endl;
		full = first+" "+last; ++count;
		setTuple(first, last, count);
		Stack12.push(pieces);
		personToQueue = make_pair(count, full);
		Queue.push_back(personToQueue);
	}
	void stackQueue() {
		for (int i = 0; i < Queue.size(); i++) {
			StackFULL.push(Queue[0]);
			Queue.pop_front();
		}
	}
};

struct Direction {
	typedef enum {
		null = 0,
		NW = 1,
		N = 2,
		NE = 3,
		W = 4,
		C = 5,
		E = 6,
		SW = 7,
		S = 8,
		SE = 9
	} Type;
};

Direction::Type dir = 9;


int main() {
	counter q;
	q.createPerson();
	q.stackQueue();
	return 0;
}