#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <ctime>
#include <bits/stdc++.h>
#include <unistd.h>
#include <time.h>
#include <memory>
#include <templatearray>
#include <queue>
#include <stack>

int increment;
vector V = vector::null;
queue Q = queue::null;
stack S = stack::null;
templatearray TA = templatearray::null;
bool skipArchive = false;

void menuInput() {
	do {
menuIn:
	std::cout << "Press 1 to enqueue the element" << std::endl;
	std::cout << "Press r to redo the element" << std::endl;
	std::cout << "Press q to quit to OS" << std::endl;
	std::string in;
	getline(std::cin, in);
	if (in == "1") {
		std::cout << "Element " << increment << " enqueued" << std::endl;
		Q = queue::ENQUEUED;
		break;
	} else if (in == "r") {
		std::cout << "Element " << increment << " string:";
		getline(std::string, input);
		std::cout << increment << "> " << input << std::endl;
		goto menuIn;
	} else if (in == "q") {
		std::cout << "Exiting to OS..." << std::endl;
		Sleep::sec(1);
	} else {
		std::cout << "Invalid input." << std::endl;
	}
	Sleep::msec(200);
	system("clear");
	} while (Q == queue::null);
}

void menuQueueAgain() {
	do {
	bool menuQA = false;
	std::cout << "Enter '1' to enter another element to the queue" << std::endl;
	std::cout << "Enter 'v' to go to the queue of elements" << std::endl;
	std::cout << "Enter 'queueall' to skip archiving, and go to the vector pairs" << std:: endl;
	std::cout << "Enter 'q' to quit to OS" << std::endl;
	std::string in;
	getline(std::cin, in);
	if (in == "1") {
		getinput();
		break;
	} else if (in == "v") {
		menuQA = true;
		toQueue();
		break;
	} else if (in == "queueall") {
		menuQA = true;
		skipArchive = true;
		toVector();
		break;
	} else if (in == "q") {
		std::cout << "Exiting to OS..." << std::endl;
		Sleep::sec(1);
	} else {
		std::cout << "Invalid input." << std::endl;
	}
	Sleep::msec(200);
	system("clear");
	} while (menuQA == false);
}

pair enqueue<increment, input>() {
	std::make_pair(increment, input) entry;
	return entry;
}

std::string input;

void getinput() {
	std::cout << "Input string: ";
	getline(std::cin, input);
	increment = count++;
	std::cout << increment << "> " << input << std::endl;
	std::endl; menuInput();
	enqueue(increment, input);
	menuQueueAgain();
}

void toVector(vector) {
	std::cout << "Copying to Vector..." << std::endl;
	for (i = 0; i < count; i++) {
		vector.push_back(pair[i]);
	}
	Sleep::msec(200);
	std::cout << "Done!" << std::endl;
	Sleep::sec(1);
	std::cout << '\n' << "Size of Vector is " << vector.size() << " elements." << std::endl;
	Sleep::sec(1);
	std::cout << "First array in memory allocation 0 is " << vector[0].first << " with the number " << vector[0].second;
	
}

bool nofile() {
	bool file = false;
	do {
	std::cout << "Do you have a file to load? (y/n)";
	std::string in;
	getline(std::cin, in);
	if (in == "y") {
		file = true;
		break;
	} else if (in == "n") {
		file = false;
		break;
	} else {
		std::cout << "Invalid input." << std::endl;
	}
	if (file = true) {
		UnZip();
		fillQueue();
		toQueue();
	}
	Sleep::msec(200);
	system("clear");
	} while (file == true);
	return file;
}

int main() {
	
nofile:
	nofile();
	do {
		getinput();
	} while (skipArchive == false || );
	toArchive();
	toVector();
	toZip();
	Zip();
	return 0;
}