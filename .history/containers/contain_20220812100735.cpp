#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <tuple>
#include <array>
using namespace std;

#define under "\033[4m"
#define _under "\033[0m"
#define upleft "\U{256D}"

void printTTT() {
	cout << endl;
	cout << " " << upleft "   |" << "   " << "|   " <<endl;
	cout << " " << under "   |" << "   " << "|   " _under <<endl;
	cout << " " << "   |" << "\\ /" << "|   " <<endl;
	cout << " " << "   |" << " X " << "|   " <<endl;
	cout << " " << under "   |" << "/ \\" << "|   " _under <<endl;
	cout << " " << "   |" << "   " << "|   " <<endl;
	cout << " " << "   |" << "   " << "|   " <<endl;
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