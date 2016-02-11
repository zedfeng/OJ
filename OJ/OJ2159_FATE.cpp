#include <iostream>
#include <climits>
using namespace std;
const int MAXLEN = 101;
//expr[i][j]表示在杀了i个怪物，剩余j耐久度时获得的经验最大值。
int expr[MAXLEN][MAXLEN];
int max(int x, int y){
	return x > y ? x : y;
}
int main(){
	int n, m, k, s, a[MAXLEN], b[MAXLEN];
	while (cin >> n >> m >> k >> s){
		for (int i = 0; i < k; i++){
			cin >> a[i] >> b[i];
		}
		memset(expr, 0, sizeof(expr));
		for (int q = 0; q < k; q++){
			for (int i = 1; i <= s; i++){
				for (int j = 0; j <= m; j++){
					if (b[q]>j){
						//如果击杀q类怪物损耗的耐久度大于剩余耐久度，只能放弃击杀。
						expr[i][j] = expr[i][j];
					}
					else{
						//否则选择是否击杀。
						expr[i][j] = max(expr[i - 1][j - b[q]] + a[q], expr[i][j]);
					}
				}
			}
		}
		if (expr[s][m] < n){
			cout << -1 << endl;
		}
		else{
			int min = INT_MAX;
			for (int i = 0; i <= s; i++){
				for (int j = 0; j <= m; j++){
					if (expr[i][j] >= n&&j < min){
						min = j;
					}
				}
			}
			cout << m - min << endl;
		}
	}
	return 0;
}