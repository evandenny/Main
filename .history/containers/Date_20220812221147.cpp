import std.io;
import calender.date;

int main() {
	using namespace Chrono;
	Date date { 12, Month::Aug, 2022 };
	std::cout << "Today is " << date << std::endl;
}