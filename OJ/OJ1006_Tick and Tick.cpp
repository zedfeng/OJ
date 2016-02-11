#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const int kTotalSecs = 60 * 60 * 24;
int main(){
	int d;
	while (cin >> d){
		if (d == -1){
			break;
		}
		double hours_deg, mins_deg, secs_deg;
		double h, m, s;
		hours_deg = mins_deg = secs_deg = 0;
		double result = 0.0;
		//Ä£ÄâÊ±ÖÓ
		for (int i = 0; i < kTotalSecs; i++){
			s = i % 60;
			m = (i / 60) % 60;
			h = (i / 3600) % 12;
			secs_deg = 6.0*s;
			mins_deg = 6.0*m + 0.1*s;
			hours_deg = 30.0*h + 0.5*m + (1.0 / 120)*s;
			if (abs(secs_deg - mins_deg) >= d&&abs(secs_deg - mins_deg) <= 360.0 - d&&abs(secs_deg - hours_deg) >= d&&abs(secs_deg - hours_deg) <= 360.0 - d&&abs(hours_deg - mins_deg) >= d&&abs(hours_deg - mins_deg) <= 360.0 - d){
				result += 1.0;
			}
		}
		cout.precision(3);
		cout << fixed << setprecision(3) << result / kTotalSecs * 100.0 << endl;
	}
	return 0;
}