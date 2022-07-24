#ifndef _Stor_template_h_
#define _Stor_template_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <templatearray>
#include <chrono>
#include <thread>
#include <iostream>

#define stringify(variable) # variable

enum class queue {
	ENQUEUED,
	null,
	DEQUEUED
};

enum class stack {
	PUT,
	null,
	POP
};

enum class vector {
	PUSHED,
	null,
	POPPED
};

enum class templatearray {
	FILL,
	ZIP,
	null,
	UNZIP,
	POP_ALL
};

class Stor {
private:
	int count;
	std::queue<pair<int, std::string>> q;
	std::stack<pair<int, std::string>> arch;
	std::vector<pair<int, std::string>> vector;
	std::templatearray<pair<int, std::string>> toZip;
public:
	Stor(queue<pair<int a, std::string b>> q, int count = 0) {
		this->q = q;
		arch = stack<pair<int, std::string>>();
		vector = vector<pair<int, std::string>>();
		toZip = templatearray<pair<int, std::string>>();
		this->count = count;
	}
	~Stor() {
		q.~queue();
		arch.~stack();
		vector.~vector();
		toZip.~templatearray();
		count.~int();
	}
	void getinput();
	pair dequeue();
	pair enqueue();
	void toQueue();
	std::string printArchiveStr();
	void toArchive();
	void toVector();
	std::string printVectorPair();
	void toZip();
	void printZipArrayTmp();
	void printZipArrayElem();
	void Zip();
	void unZip();
	void fillQueue();
	void ArchiveShred();
	void VectorShred();
	void ZipShred();
	}
};

class Sleep {
public:
	static void sec(int seconds) {
		std::this_thread::sleep_for(std::chrono::seconds(seconds));
	}
	static void msec(int milliseconds) {
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
	}
	static void usec(int microseconds) {
		std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
	}
};

#endif