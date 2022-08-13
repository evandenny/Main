#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <tuple>
#include <vector>
#include <deque>
#include <stack>
using namespace std;



namespace Dir {
	enum Direction {
		null = 0,
		NW = 1,
		N = 2,
		NE = 3
	};
};

int Array{3}{3} = [[1, 2, 3],
				   [1, 2, 3],
				   [1, 2, 3]];
auto position = Dir::Direction::null;

Dir::Direction dir = Dir::Direction::null;

int main() {
	counter q;
	q.createPerson();
	q.stackQueue();
	return 0;
}