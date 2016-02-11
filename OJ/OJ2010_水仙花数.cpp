#include<iostream>
using namespace std;
const int kMaxLen = 1000;
int num[kMaxLen];
int main(){
	int m, n, count;
	while (cin >> m >> n){
		count = 0;
		for (int i = m; i <= n; i++){
			int sum = 0;
			int temp, res;
			temp = i;
			while (temp != 0){
				res = temp % 10;
				sum += res*res*res;
				temp /= 10;
			}
			if (sum == i){
				num[count++] = i;
			}
		}
		if (count != 0){
			for (int i = 0; i < count - 1; i++){
				cout << num[i] << " ";
			}
			cout << num[count - 1] << endl;
		}
		else{
			cout << "no" << endl;
		}
	}
	return 0;
}