#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <tuple>
#include <vector>
#include <deque>
#include <stack>
#include "AppCPP/Sleep.h"
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
		setTuple(first, last, count)
		Stack.push(pieces);
		p
	}
};
