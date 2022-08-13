import std.io;
import std.string;
import calendar.month;

module Calendar.date;

namespace Chrono {
	export
	 struct Date {
		Date(int, Month, int);
		int day() const {return d;}
		Month month() const {return m;}
	 }
}