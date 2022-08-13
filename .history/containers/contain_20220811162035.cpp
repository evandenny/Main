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
	void createPerson() {
		cout << "[ENTER YOUR FIRST NAME]>-";
		getline(cin, first);
		cout << "[ENTER YOUR LAST NAME]>-";
		getline(cin, last);
		cout << "Queuing person..." << endl;
		full = first+" "+last;
		pieces[0] = ++count;
		pieces[1] = first;
		pieces[2] = last;
		Queue.push_back(pieces)
	}
};
