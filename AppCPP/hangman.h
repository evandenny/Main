#ifndef _hangman_h_
#define _hangman_h_

class HANGMAN {
public:
	static void game();
	static void initArray();
	static void loss();
	static void printHangman();
	static void printWrong();
	static void check();
	static void checkWin();
	static void printLines2();
	static void getInput();
	static void redraw();
	static void play();
	static void printHint();
};

#endif