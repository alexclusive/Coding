#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Time {
	public:
		int weeks = 0;
		int days = 0;
		int hours = 0;
		int mins = 0;
		int secs = 0;

		void validate() {
			if (abs(secs) >= 60) {
				mins += secs / 60;
				secs %= 60;
			}
			if (abs(mins) >= 60) {
				hours += mins / 60;
				mins %= 60;
			}
			if (abs(hours) >= 24) {
				days += hours / 24;
				hours %= 24;
			}
			if (abs(days) >= 7) {
				weeks += days / 7;
				days %= 7;
			}
		}

		Time(int w, int d, int h, int m, int s) {
			secs = s;
			mins = m;
			hours = h;
			days = d;
			weeks = w;
			validate();
		}

		Time(int d, int h, int m, int s) {
			secs = s;
			mins = m;
			hours = h;
			days = d;
			validate();
		}

		Time(int h, int m, int s) {
			secs = s;
			mins = m;
			hours = h;
			validate();
		}

		Time(int h, int m) {
			mins = m;
			hours = h;
			validate();
		}

		Time(int m) {
			mins = m;
			validate();
		}

		Time() {
		}

		void add(Time* toAdd) {
			secs += toAdd->secs;
			mins += toAdd->mins;
			hours += toAdd->hours;
			days += toAdd->days;
			weeks += toAdd->weeks;
			validate();
		}

		bool isZero() {
			return secs == 0
				&& mins == 0
				&& hours == 0
				&& days == 0
				&& weeks == 0;
		}

		string toString() {
			string str = "";
			if (weeks > 0) {
				if (str.length() != 0) {
					str += " ";
				}
				str += to_string(weeks) + " week";
				if (weeks > 1) {
					str += "s";
				}
			}
			if (weeks > 0 && days > 0) {
				str += ",";
			}

			if (days > 0) {
				if (str.length() != 0) {
					str += " ";
				}
				str += to_string(days) + " day";
				if (days > 1) {
					str += "s";
				}
			}
			if (days > 0 && hours > 0) {
				str += ",";
			}

			if (hours > 0) {
				if (str.length() != 0) {
					str += " ";
				}
				str += to_string(hours) + " hour";
				if (hours > 1) {
					str += "s";
				}
			}
			if (hours > 0 && mins > 0) {
				str += ",";
			}

			if (mins > 0) {
				if (str.length() != 0) {
					str += " ";
				}
				str += to_string(mins) + " minute";
				if (mins > 1) {
					str += "s";
				}
			}
			if (mins > 0 && hours > 0) {
				str += ",";
			}

			if (secs > 0) {
				if (str.length() != 0) {
					str += " ";
				}
				str += to_string(secs) + " second";
				if (secs > 1) {
					str += "s";
				}
			}

			if (str.length() == 0) {
				str = "No time elapsed.";
			}

			return str;
		}
};

class TimeAdder {
	public:
		Time total;
		vector<Time> times;

		TimeAdder() {
			total = Time();
			times = {};
		}

		void insert(Time toInsert) {
			times.push_back(toInsert);
		}

		void addAllTimes() {
			for (auto time : times) {
				total.add(&time);
			}
		}

		Time getTotal() {
			addAllTimes();
			return total;
		}
};

int main() {
	TimeAdder adder;
	adder.insert(Time(1236,17,07));
	cout << "Total: " << adder.getTotal().toString() << endl;
}