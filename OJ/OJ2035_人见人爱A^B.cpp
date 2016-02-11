#include<iostream>
using namespace std;
int main(){
	int a, b;
	while (cin >> a >> b){
		if (a == 0 && b == 0){
			break;
		}
		int result = 1;
		while (b--){
			result = result*a % 1000;
		}
		cout << result << endl;
	}
}