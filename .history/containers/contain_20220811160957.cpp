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
	pair<int, string> person;
	tuple<int, string, string> toQueue;
	deque<pair<int, string>> Queue;