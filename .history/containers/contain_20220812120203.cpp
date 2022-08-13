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
#define xXx "\u2573"
#define oOo "\u25EF"
#define vert  "\uFE31"

struct TTT {
	char n=' ',nw=n,ne=n,w=n,c=n,e=n,sw=n,s=n,se=n;
	vector<char> pos = { nw, n, ne, w, c, e, sw, s, se };
	void resetChars() {
		for (int i = 0; i < pos.size(); i++) {
			pos[i] = ' ';
		}
	}
	void setChars() {
		n = pos[1];
		nw = pos[0];

	}
	void setCharX(char character) {
		char a = 'a';
	}
} ttt;

namespace Direction {
	enum Dir {
		null = 9,
		NW = 0,
		N = 1,
		NE = 2,
		W = 3,
		C = 4,
		E = 5,
		SW = 6,
		S = 7,
		SE = 8
	};
};

using namespace Direction;

Dir direction = null;

vector<[int]()->(new uint8)> Board = {{1,2},{1,2}};


void printTTT() {
	cout << endl;
	cout << " " << under << ttt.pos[0] << vert << ttt.pos[1] << vert << ttt.pos[2] << _under << endl;
	cout << " " << under << ttt.pos[3] << vert << ttt.pos[4] << vert << ttt.pos[5] << _under << endl;
	cout << " " << ttt.pos[6] << vert << ttt.pos[7] << vert << ttt.pos[8] << endl;
	cout << endl;
}

int main() {
	
	return 0;
}