#include <iostream>
using namespace std;
const int MAX = 6000;
int min(int x, int y){
	return x < y ? x : y;
}
int main(){
	int t, n, result[MAX + 1];
	result[0] = result[1] = 1;
	int f2, f3, f5, f7;
	f2 = f3 = f5 = f7 = 1;
	for (int i = 2; i <= 6000; i++){
		result[i] = min(min(min(result[f2] * 2, result[f3] * 3), result[f5] * 5), result[f7] * 7);
		if (result[i] / 2 == result[f2]){
			f2++;
		}
		if (result[i] / 3 == result[f3]){
			f3++;
		}
		if (result[i] / 5 == result[f5]){
			f5++;
		}
		if (result[i] / 7 == result[f7]){
			f7++;
		}
	}
	while (cin >> n&&n){
		t = n / 10;
		if (n % 10 == 1 && t % 10 != 1){
			cout << "The " << n << "st humble number is " << result[n] << "." << endl;
		}
		else if (n % 10 == 2 && t % 10 != 1){
			cout << "The " << n << "nd humble number is " << result[n] << "." << endl;
		}
		else if (n % 10 == 3 && t % 10 != 1){
			cout << "The " << n << "rd humble number is " << result[n] << "." << endl;
		}
		else{
			cout << "The " << n << "th humble number is " << result[n] << "." << endl;
		}
	}
	return 0;
}