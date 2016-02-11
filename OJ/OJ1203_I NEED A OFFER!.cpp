#include<iostream>
#include<iomanip>
using namespace std;
const int kMaxLen = 10001;
int fee[kMaxLen];
double offer[kMaxLen];
double nooffer[kMaxLen];
double min(double x, double y){
	return x > y ? y : x;
}
int main(){
	int n, m;
	while (cin >> n >> m){
		if (n == 0 && m == 0){
			break;
		}
		for (int i = 0; i < m; i++){
			cin >> fee[i] >> offer[i];
		}
		for (int i = 0; i <= n; i++){
			nooffer[i] = 1.0;
		}
		for (int i = 0; i < m; i++){
			for (int j = n; j - fee[i] >= 0; j--){
				//Ñ¹Ëõ¶þÎ¬Êý×é
				nooffer[j] = min(nooffer[j], nooffer[j - fee[i]] * (1 - offer[i]));
			}
		}
		cout << fixed << setprecision(1) << (1 - nooffer[n]) * 100 << "%" << endl;
	}
	return 0;
}