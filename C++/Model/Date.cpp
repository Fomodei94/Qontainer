#include "Date.h"

Date::Date(int d, int m, int y): day(d), month(m), year(y) {
	if(!isDateCorrect(d, m, y)) {
		throw("Wrong Date Format");
	} 
}

bool Date::isDateCorrect(int d, int m, int y) {
	if(y<2150 && y>1850 && m>=1 && m<=12) {
		if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12 && d>=1 && d<=31) {
			return true;
		} 
		else if(m==2 && d>=1 && d<=29) {
			return true;
		}
		else if(m==4 || m==6 || m==9 || m==11 && d>=1 && d<=30) {
			return true;
		}
		else {
			return false;
		}
	}
	else return false;
}

string Date::printDateString(int d, int m, int y) {
	string result = to_string(y) + "-" + to_string(m) + "-" + to_string(d);
	return result;
}

int Date::getDay() {
	return day;
}

int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

void Date::setDay(int d) {
	if(isDateCorrect(d, month, year)) {
		day = d;
	} else {
		throw("Wrong Date Format");
	}
}

void Date::setMonth(int m) {
	if(isDateCorrect(day, m, year)) {
		month = m;
	} else {
		throw("Wrong Date Format");
	}
}

void Date::setYear(int y) {
	if(isDateCorrect(day, month, y)) {
		year = y;
	} else {
		throw("Wrong Date Format");
	}
}
