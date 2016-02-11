#include<iostream>
using namespace std;
int main(){
	int n, m, num;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> m;
		int sum = 0;
		while (m--){
			cin >> num;
			sum += num;
		}
		if (i < n - 1){
			cout << sum << endl;
			cout << endl;
		}
		else{
			cout << sum << endl;
		}
	}
	return 0;
}