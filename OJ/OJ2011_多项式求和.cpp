#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n, m;
	double result;
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> n;
		result = 0.0;
		for (int j = 1; j <= n; j++){
			result += j % 2 == 0 ? -1.0 / j : 1.0 / j;
		}
		cout << fixed << setprecision(2) << result << endl;
	}
	return 0;
}