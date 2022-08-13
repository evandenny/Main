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
	std::tuple<int, string, string> toQueue;
	std:deque<tuple<int, string, string>