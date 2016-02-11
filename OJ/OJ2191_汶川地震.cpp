#include <iostream>
using namespace std;
const int LEN = 101;
int rice[LEN][3];
int riceByBag[LEN * 20][2];
//maxweight[i][j]表示在有i袋大米和j资金的前提下购得最重大米数。
int maxWeight[LEN * 20][LEN];
int max(int x, int y){ return x > y ? x : y; }
int main(){
	int C, n, m, totalNum;
	cin >> C;
	while (C--){
		cin >> n >> m;
		totalNum = 0;
		for (int i = 0; i < m; i++){
			cin >> rice[i][0] >> rice[i][1] >> rice[i][2];
			for (int j = totalNum; j < totalNum + rice[i][2]; j++){
				riceByBag[j][0] = rice[i][0];
				riceByBag[j][1] = rice[i][1];
			}
			totalNum += rice[i][2];
		}
		memset(maxWeight, 0, sizeof(maxWeight));
		for (int i = 1; i <= totalNum; i++){
			for (int j = 0; j <= n; j++){
				if (riceByBag[i - 1][0] > j){
					//当前大米价格过高，无法收购。
					maxWeight[i][j] = maxWeight[i - 1][j];
				}
				else{
					maxWeight[i][j] = max(maxWeight[i - 1][j - riceByBag[i - 1][0]] + riceByBag[i - 1][1], maxWeight[i - 1][j]);
				}
			}
		}
		cout << maxWeight[totalNum][n] << endl;
	}
}