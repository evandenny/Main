#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

void printTTT() {
	cout << "_|" << "_" << "|_" <<endl;
	cout << "_|" << "_" << "|_" <<endl;
	cout << " |" << "_" << "| " <<endl;
}

namespace Dir {
	enum Direction {
		null = 0,
		NW = 1,
		N = 2,
		NE = 3
	};
};

int Array{{}} = [[1, 2, 3],
				 [1, 2, 3],
				 [1, 2, 3]];
auto position = Dir::Direction::null;

Dir::Direction dir = Dir::Direction::null;

int main() {
	printTTT();
	return 0;
}