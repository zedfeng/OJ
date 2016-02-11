#include<iostream>
using namespace std;
const int kMaxCost = 1000000;
const int kMaxMonth = 13;
const int kMaxHire = 101;
int min_num[kMaxMonth];
int cost[kMaxMonth][kMaxHire];
int min(int, int);
int main(){
	int month, hire_cost, fire_cost, salary;
	while (cin >> month){
		if (month == 0){
			break;
		}
		cin >> hire_cost >> salary >> fire_cost;
		for (int i = 0; i < month; i++){
			cin >> min_num[i];
		}
		memset(cost, kMaxCost, sizeof(cost));
		for (int i = 0; i < month; i++){
			for (int j = min_num[i]; j < kMaxHire; j++){
				if (i == 0){
					cost[i][j] = j*hire_cost + j*salary;
				}
				else{
					for (int k = min_num[i - 1]; k < kMaxHire; k++){
						int temp;
						if (k <= j){
							temp = min(cost[i - 1][j], cost[i - 1][k] + (j - k)*hire_cost) + j*salary;
						}
						else{
							temp = min(cost[i - 1][j], cost[i - 1][k] + (k - j)*fire_cost) + j*salary;
						}
						if (cost[i][j] > temp){
							cost[i][j] = temp;
						}
					}
				}
			}
		}
		int result = kMaxCost;
		for (int k = min_num[month - 1]; k < kMaxHire; k++){
			if (result>cost[month - 1][k]){
				result = cost[month - 1][k];
			}
		}
		cout << result << endl;
	}
	return 0;
}
int min(int x, int y){
	return x > y ? y : x;
}