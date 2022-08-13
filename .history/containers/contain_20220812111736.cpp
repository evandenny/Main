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
#define x "\u2573"
#define vert  "\uFE31"

struct TTT {
	char n=' ',nw=n,ne=n,w=n,c=n,e=n,sw=n,s=n,se=n;
	vector<char> pos = { nw, n, ne, w, c, e, sw, s, se };
	void resetChars() {
		for (int i = 0; i < pos.size(); i++) {
			pos[i] = ' ';
		}
	}
} ttt;

namespace Direction {
	enum Dir {
		null = 0,
		NW = 1,
		N = 2,
		NE = 3,
		W = 4,
		C = 5,
		E = 6,
		SW = 7,
		S = 8,
		SE = 9
	};
};

using namespace Direction;

Dir direction = null;

int array[3][3] = {1,2,3,1,2,3,1,2,3};

void printTTT() {
	cout << endl;
	cout << " " << under << ttt.pos[0] << vert << ttt.pos[1] << vert << ttt.pos[2] << _under << endl;
	cout << " " << under << ttt.pos[3] << vert <<" "<< vert << " " _under << endl;
	cout << " " <<       " " << vert <<" "<< vert << " " << endl;
	cout << endl;
}

int main() {
	
	return 0;
}