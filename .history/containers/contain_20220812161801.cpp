#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <tuple>
#include <array>
#include <cmath>
using namespace std;

#define under "\033[4m"
#define _under "\033[0m"
#define xXx '\u2573'
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

vector<vector<char>> Board {
	{ttt.pos[0], ttt.pos[1], ttt.pos[2]},
	{ttt.pos[3], ttt.pos[4], ttt.pos[5]},
	{ttt.pos[6], ttt.pos[7], ttt.pos[8]}
};


class TicTacToe {
private:
	bool xWin = false;
	bool oWin = false;
	char cValue;
public:
	bool winBool() {
		return xWin || oWin;
	}
	void play() {
		bool value = winBool();
		this->cValue = (char)xXx;
		do {
			system("clear");
			t.printTTT();
		} while (value);
	}
};

int main() {
	system("clear");
	TicTacToe game;
	game.play();
	return 0;
}