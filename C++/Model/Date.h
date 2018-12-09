#include <string>
using std::string;
using std::to_string;

class Date {
			private:
				int day,
					month,
					year;
			public:
				//CONSTRUCTOR:
				Date(int d, int m, int y);
				//GETTERS:
				int getDay();
				int getMonth();
				int getYear();
				//SETTERS:
				void setDay(int d);
				void setMonth(int m);
				void setYear(int y);
				//CONSISTENCE CHECK:
				bool isDateCorrect(int d, int m, int y);
				//PRINTING FUNCTION:
				string printDateString(int d, int m, int y);
		};
