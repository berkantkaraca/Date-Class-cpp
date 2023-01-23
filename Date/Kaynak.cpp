#include "Date.h"
using namespace std;

int main() {
	Date date1(13, 11, 2002);
	Date date2(date1);
	
	date1.displayDate();
	for (int i = 0; i <= 365;i++) {
		date1.increaseDay();
		date1.displayDate();
	}

	cout << endl;
}

