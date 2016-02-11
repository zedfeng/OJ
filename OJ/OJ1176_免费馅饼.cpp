#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
const int MAXLEN = 100010;
int numPie[MAXLEN][11];
int maxNum(int left, int mid, int right){
	return (left > mid) ? (left > right ? left : right) : (mid > right ? mid : right);
}
int main(){
	int n;
	while (scanf("%d", &n) != EOF&&n){
		memset(numPie, 0, sizeof(numPie));
		int time, pos, timeout;
		timeout = INT_MIN;
		for (int i = 0; i < n; i++){
			scanf("%d %d", &pos, &time);
			numPie[time][pos]++;
			if (timeout < time){
				timeout = time;
			}
		}
		int left, right, mid, max;
		max = INT_MIN;
		for (int i = timeout - 1; i >= 0; i--){
			for (int j = 0; j < 11; j++){
				left = j == 0 ? 0 : j - 1;
				right = j == 10 ? 10 : j + 1;
				mid = j;
				numPie[i][j] += maxNum(numPie[i + 1][left], numPie[i + 1][mid], numPie[i + 1][right]);
			}
		}
		printf("%d\n", numPie[0][5]);
	}
	return 0;
}