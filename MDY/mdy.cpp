#include <bits/types/struct_tm.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include "SLP.h"

#define stringify(x) #x                                                                       
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
	std::string getLocalTime() {
		time_t now;
		now = time(NULL);
		tm *tm_local = localtime(&now);
		std::cout << "Today is " << Ltime::getDay() << ", " << tm_local->tm_mon+1 << "/" << tm_local->tm_mday << "/" << tm_local->tm_year + 1900 << std::endl;
		return std::to_string(tm_local->tm_mon+1) + "/" + std::to_string(tm_local->tm_mday) + "/" + std::to_string(tm_local->tm_year + 1900);
	}
	enum wday getDay() {
		time_t now;
		now = time(NULL);
		tm *tm = localtime(&now);
		int day = tm->tm_wday;
		wday d = wday(day);
		return d;
	}
	enum wday {
		Sunday,
		Monday,
		Tuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday
	};
	enum month {
		January,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};
	void getdate();
	void gettime();
};

void getLocalTime() {

}

int main() {
	Ltime lt;
	lt.local();
	std::cout << lt.getDay() << std::endl;
	return 0;
}