#include <iostream>
using namespace std;
const int MAXLEN = 101;
int mat[MAXLEN][MAXLEN];
int max[MAXLEN][MAXLEN];
int findMax(int i, int j, int k, int n){
	if (max[i][j] != -1){
		return max[i][j];
	}
	max[i][j] = mat[i][j];
	for (int m = 1; m <= k; m++){
		if (i - m >= 0 && mat[i - m][j] > mat[i][j]){
			max[i - m][j] = findMax(i - m, j, k, n);
			max[i][j] = max[i][j] > (max[i - m][j] + mat[i][j]) ? max[i][j] : (max[i - m][j] + mat[i][j]);
		}
		if (i + m <n && mat[i + m][j] > mat[i][j]){
			max[i + m][j] = findMax(i + m, j, k, n);
			max[i][j] = max[i][j] > (max[i + m][j] + mat[i][j]) ? max[i][j] : (max[i + m][j] + mat[i][j]);
		}
		if (j - m >= 0 && mat[i][j - m] > mat[i][j]){
			max[i][j - m] = findMax(i, j - m, k, n);
			max[i][j] = max[i][j] > (max[i][j - m] + mat[i][j]) ? max[i][j] : (max[i][j - m] + mat[i][j]);
		}
		if (j + m<n && mat[i][j + m] > mat[i][j]){
			max[i][j + m] = findMax(i, j + m, k, n);
			max[i][j] = max[i][j] > (max[i][j + m] + mat[i][j]) ? max[i][j] : (max[i][j + m] + mat[i][j]);
		}
	}
	return max[i][j];
}
int main(){
	int n, k;
	while (cin >> n >> k){
		if (n == -1 && k == -1){
			break;
		}
		memset(mat, 0, sizeof(mat));
		memset(max, -1, sizeof(max));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> mat[i][j];
			}
		}
		cout << findMax(0, 0, k, n) << endl;
	}
	return 0;
}