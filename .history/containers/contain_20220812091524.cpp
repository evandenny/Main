#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <tuple>
#include <array>
using namespace std;

void printTTT() {
	cout << endl;
	cout << "  " << "__|" << "_" << "|_" <<endl;
	cout << "  " << "__|" << "_" << "|_" <<endl;
	cout << "  " << "  |" << " " << "| " <<endl;
}

namespace Dir {
	enum Direction {
		null = 0,
		NW = 1,
		N = 2,
		NE = 3,
		W = 4,
		C = 5,
		E = 6
	};
};

int array[3][3] = {1,2,3,1,2,3,1,2,3};

auto position = Dir::Direction::null;

Dir::Direction dir = Dir::Direction::null;

int main() {
	printTTT();
	return 0;
}