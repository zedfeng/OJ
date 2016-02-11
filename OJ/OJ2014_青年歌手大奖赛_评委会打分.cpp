#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n;
	double score, sum_score, max, min;
	while (cin >> n){
		sum_score = 0.0;
		max = -1.0;
		min = 101.0;
		for (int i = 0; i < n; i++){
			cin >> score;
			sum_score += score;
			if (score > max){
				max = score;
			}
			if (score < min){
				min = score;
			}
		}
		cout << fixed << setprecision(2) << (sum_score - max - min) / (n - 2) << endl;
	}
	return 0;
}