#include <bits/types/struct_tm.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include "SLP.h"
                                                                                                         
class Ltime {
private:
	
public:
	Ltime() {
		time_t now;
		now = time(NULL);
		tm *tm_local = localtime(&now);
		time_t tm_mday = tm_mday;
		time_t tm_mon = tm_mon + 1;
		time_t tm_year = tm_year + 1900;
		time_t tm_hour = tm_hour;
		time_t tm_min = tm_min;
	}
	void local() {
		time_t now;
		now = time(NULL);
		tm *tm_local = localtime(&now);
		std::cout << "Local time and date: ";
		std::cout << tm_local->tm_mon + 1 << "/" << tm_local->tm_mday << "/" << tm_local->tm_year + 1900 << std::endl;
	}
	void getLocalTime() {
		time_t now;
		now = time(NULL);
		tm *tm_local = localtime(&now);

	}
	void getdate();
	void gettime();
};

void getLocalTime() {

}

int main() {
	Ltime lt;
	lt.local();
	return 0;
}