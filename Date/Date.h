#include <iostream>
using namespace std;

class Date {
public:
	Date(int d = 1, int m = 1, int y = 1900);
	Date(const Date& oth);
	~Date();
	
	void setDate(int d = 1, int m = 1, int y = 1900);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }

	void increaseDay();
	void compareDate(const Date& othDate);
	void displayDate();
	bool operator==(const Date& othDate);
private:
	int year, month, day;
	const int monthDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	const string monthString[12] = { "Ocak","Subat","Mart","Nisan","Mayis","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik" };
};

//Constructor
Date::Date(int d, int m, int y) {
	cout << "Constructor calisti" << endl;
	setDate(d, m, y);
}

//Copy Constructor
Date::Date(const Date& oth) {
	cout << "Copy Constructor calisti" << endl;
	day = oth.day;
	month = oth.month;
	year = oth.year;
}

//Destructor
Date::~Date() {
	cout << "Destructor calisti" << endl;
}

void Date::displayDate() {
	cout << "Tarih(g-a-y): " << getDay() << "." << getMonth() << "." << getYear() << endl;
}

void Date::setDay(int d) {

	while (!(0 < d && d <= monthDays[month - 1])) {
		cout << monthString[month - 1] << " Ayi " << monthDays[month - 1] << " gundur." << endl;
		cout << "Gun sayisi hatali girildi! Lutfen tekrar girin: ";
		cin >> d;
	}
	day = d;
}

void Date::setMonth(int m) {

	while (!(0 < m && m < 13)) {
		cout << "Ay sayisi hatali girildi! Lutfen tekrar girin: ";
		cin >> m;
	}
	month = m;
}

void Date::setYear(int y) { year = y; }

void Date::setDate(int d, int m, int y) {
	setMonth(m); // day kontrolünde month deðiþkenini kullandýðýmýz için ilk önce setMonth çalýþtýrdýk
	setDay(d);
	setYear(y);
}

void Date::increaseDay() {
	day += 1;

	if (monthDays[month - 1] < day) {
		day = 1;
		month += 1;
		if (month > 12) {
			month = 1;
			year += 1;
		}
	}
}

void Date::compareDate(const Date& othDate) {
	//year * 360 + month * 30 + day formülü ile iki tarihi karþýlaþtýrabilirsin
	if (day == othDate.getDay() && month == othDate.getMonth() && year == othDate.getYear()) {
		cout << "Tarihler esit";
	}
	else {
		cout << "Tarihler esit degil";
	}
}

//opertar overload
bool Date::operator==(const Date& othDate) {
	return ((day == othDate.getDay() && month == othDate.getMonth() && year == othDate.getYear()));
}