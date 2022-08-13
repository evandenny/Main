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

namespace Dir {
	enum Direction {
		null,
		NW,
		N,
		NE
	};
};

int Array{3}{3} = [[1, 2, 3],
				   [1, 2, 3],
				   [1, 2]]

Dir::Direction direction = Dir::Direction::null;
void func() {
	switch (direction) {
		case 0:
			//do nothing
			break;
		case 1:

	}
}

int main() {
	counter q;
	q.createPerson();
	q.stackQueue();
	return 0;
}