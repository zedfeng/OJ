#include<iostream>
using namespace std;
char date[11];
bool isLeapYear(int year){
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
		return true;
	}
	return false;
}
int main(){
	int t, year, month, day;
	cin >> t;
	while (t--){
		cin >> date;
		year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
		month = (date[5] - '0') * 10 + (date[6] - '0');
		day = (date[8] - '0') * 10 + (date[9] - '0');
		int days = 0;
		if (month == 2 && day == 29){
			cout << -1 << endl;
			continue;
		}
		else{
			days = 0;
			for (int i = 1; i < 18; i++){
				if (isLeapYear(year + i)){
					days++;
				}
			}
			if (isLeapYear(year) && month < 3){
				days++;
			}
			if (isLeapYear(year + 18) && month >= 3){
				days++;
			}
			days += 18 * 365;
		}
		cout << days << endl;
	}
	return 0;
}