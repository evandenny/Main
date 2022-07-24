#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <chrono>
#include <ctime>
#include <thread>
#include <time.h>
#include <unistd.h>
#include <limits>
#include <fstream>
#include <sstream>
#include <ios>
#include <bits/stdc++.h>
#include <iomanip>

#define stringify(x) #x
#define to_string(x) stringify(x)
#define underline "\033[4m"
#define reset "\033[0m"

class Sleep {
public:
	static void seconds(int seconds) {
		std::this_thread::sleep_for(std::chrono::seconds(seconds));
	}
	static void milliseconds(int milliseconds) {
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
	}
	static void microseconds(int microseconds) {
		std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
	}
};

class PhoneBook {
private:
	std::map<std::string, std::string> phoneBook;
	std::map<std::string, std::string>::iterator it;
	std::string name;
	std::string phoneNumber;
	std::string input;
	std::string output;
	int size = 0;
public:
	PhoneBook() {
		phoneBook;
		it;
		name;
		phoneNumber;
		input;
		output;
		size = 0;
	}
	~PhoneBook() {
		phoneBook.clear();
		it;
		name;
		phoneNumber;
		input;
		output;
		size;
	}
	void gotomenu() {
		system("clear");
		menu();
	}
	void addEntry() {
		std::cout << "Current number of entries: " << phoneBook.size() << "\n" << std::endl;
		Sleep::seconds(1);
		std::cout << underline "New entry:" reset << std::endl;		
		Sleep::milliseconds(300);
		std::cout << "Enter name: ";
		std::cin.ignore();
		std::cin.clear();
		getline(std::cin, name);
		Sleep::milliseconds(300);
		std::cout << "Enter phone number: ";
		std::cin.clear();
		std::cin >> phoneNumber;
		Sleep::milliseconds(300);
		phoneBook[name] = phoneNumber;
		++size;
		if (size < 2){
		std::cout << "New phonebook size: " << phoneBook.size() << " entry.\n";
		} else if (size >= 2) {
		std::cout << "New phonebook size: " << phoneBook.size() << " entries.\n";
		}
		Sleep::seconds(2);
	}
	void searchEntry() {

	}
	void deleteMenu() {
		std::cout << "Current number of entries: " << phoneBook.size() << std::endl;
		Sleep::seconds(1);
		std::cout << "Latest entry: " << phoneBook.rbegin()->first << " " << phoneBook.rbegin()->second << std::endl;
		Sleep::seconds(1);
	deletemainmenu:
		std::cout << "1. Delete latest entry" << std::endl;
		std::cout << "2. Delete entry by name" << std::endl;
		std::cout << "3. Delete entry by phone number" << std::endl;
		std::cout << "4. Delete all entries" << std::endl;
		std::cout << "5. Back to menu" << std::endl;
		std::cin.ignore();
		std::cin.clear();
		getline(std::cin, input);
		Sleep::milliseconds(180);
		system("clear");
		switch (input[0]) {
		case '1':
			phoneBook.erase(phoneBook.rbegin()->first);
			size--;
			if (size < 2){
			std::cout << "New phonebook size: " << phoneBook.size() << " entry.\n";
			} else if (size >= 2) {
			std::cout << "New phonebook size: " << phoneBook.size() << " entries.\n";
			}
			Sleep::seconds(2);
			break;
		case '2':
			std::cout << "Enter name: ";
			getline(std::cin, name);
			Sleep::milliseconds(300);
			phoneBook.erase(name);
			size--;
			if (size < 2){
			std::cout << "New phonebook size: " << phoneBook.size() << " entry.\n";
			} else if (size >= 2) {
			std::cout << "New phonebook size: " << phoneBook.size() << " entries.\n";
			}
			Sleep::seconds(2);
			break;
		case '3':
			std::cout << "Enter phone number: ";
			std::cin.clear();
			std::cin >> phoneNumber;
			Sleep::milliseconds(300);
			phoneBook.erase(phoneNumber);
			size--;
			if (size < 2){
			std::cout << "New phonebook size: " << phoneBook.size() << " entry.\n";
			} else if (size >= 2) {
			std::cout << "New phonebook size: " << phoneBook.size() << " entries.\n";
			}
			Sleep::seconds(2);
			break;
		case '4':
		deletemenu:
			std::cout << "Are you sure you want to delete all entries? (y/n) ";
			getline(std::cin, input);
			Sleep::milliseconds(300);
			if (input[0] == 'y') {
				phoneBook.clear();
				size = 0;
				std::cout << underline "All entries deleted." reset << std::endl;
				std::cout << "New phonebook size: " << phoneBook.size() << " entries.\n";
				Sleep::seconds(2);
				break;
			} else if (input[0] == 'n') {
				std::cout << "Returning to menu..." << std::endl;
				Sleep::seconds(2);
				break;
			} else {
				std::cout << "Invalid input!" << std::endl;
				Sleep::seconds(1);
				system("clear");
				goto deletemenu;
			}
			break;
		case '5':
			gotomenu();
		default:
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input!" << std::endl;
			Sleep::seconds(1);
			system("clear");
			goto deletemainmenu;
		}

	}
	void gotoDeleteMenu() {
		system("clear");
		deleteMenu();
	}
	void printPhoneBook() {
		for (it = phoneBook.begin(); it != phoneBook.end(); ++it) {
			std::cout << it->first << " " << it->second << std::endl;
		}
	}
	void menu() {
		do {
		system("clear");
		std::cout << "1. Add entry\n";
		std::cout << "2. Search entry\n";
		std::cout << "3. Delete entry\n";
		std::cout << "4. Print phone book\n";
		std::cout << "5. Exit\n";
		switch(std::cin.get()) {
			case '1':
				addEntry();
				break;
			case '2':
				searchEntry();
				break;
			case '3':
				gotoDeleteMenu();
				break;
			case '4':
				printPhoneBook();
				break;
			case '5':
				exit(0);
				break;
			default:
				std::cout << "Invalid input\n";
				break;
		}
		} while(true); //loop forever | main loop until user decides to exit.
	}
};


int main() {
	PhoneBook phoneBook;
	phoneBook.menu();
	return 0;
}