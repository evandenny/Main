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
	int count;
	string first, last, full;
	pair<int, string> personToQueue;
	tuple<int, string, string> pieces;
	deque<pair<int, string>> Queue;
	stack<pair<int, string>> Stack;
	void createPerson() {
		cout << "ENTER YOUR FIRST NAME=>"
	}
};
