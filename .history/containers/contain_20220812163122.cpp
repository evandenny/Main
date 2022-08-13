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
#define xXx 'X'
#define oOo 'O'
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


char NorthWest = Board[0][0];
char North = Board [1][0];
char NorthEast = Board[2][0];
char West = Board[0][1];
char Center = Board[1][1];
char East = Board[2][1];
char SouthWest = Board[0][2];
char South = Board[1][2];
char SouthEast = Board[2][2];

void printTTT() {
	cout << under << " TIC TAC TOE " << _under << endl;
	cout << vert << "         " << vert << endl;
	cout << vert << " " << under << ttt.pos[0] << vert << 'X' << vert << ttt.pos[2] << _under << " " << vert << endl;
	cout << vert << " " << under << ttt.pos[3] << vert << ttt.pos[4] << vert << ttt.pos[5] << _under << " " << vert << endl;
	cout << vert << " " << ttt.pos[6] << vert << ttt.pos[7] << vert << ttt.pos[8] << " " << endl;
	cout << under << vert <<"         "<<vert<<_under<< endl;
}


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
			printTTT();
		} while (value);
	}
};

int main() {
	system("clear");
	TicTacToe game;
	game.play();
	return 0;
}