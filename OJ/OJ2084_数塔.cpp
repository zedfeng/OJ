#include <iostream>
using namespace std;
int main(){
	int C, N, result[101][101];
	cin >> C;
	while (C--){
		cin >> N;
		for (int i = 0; i < N; i++){
			for (int j = 0; j <= i; j++){
				cin >> result[i][j];
			}
		}
		for (int i = 1; i < N; i++){
			for (int j = 0; j <= i; j++){
				if (j == 0){
					result[i][j] += result[i - 1][j];
				}
				else if (j == i){
					result[i][j] += result[i - 1][j - 1];
				}
				else{
					result[i][j] += result[i - 1][j - 1] > result[i - 1][j] ? result[i - 1][j - 1] : result[i - 1][j];
				}
			}
		}
		int max = 0;
		for (int i = 0; i < N; i++){
			if (max < result[N - 1][i]){
				max = result[N - 1][i];
			}
		}
		cout << max << endl;
	}
	return 0;
}