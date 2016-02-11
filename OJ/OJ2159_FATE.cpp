#include <iostream>
#include <climits>
using namespace std;
const int MAXLEN = 101;
//expr[i][j]��ʾ��ɱ��i�����ʣ��j�;ö�ʱ��õľ������ֵ��
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
						//�����ɱq�������ĵ��;öȴ���ʣ���;öȣ�ֻ�ܷ�����ɱ��
						expr[i][j] = expr[i][j];
					}
					else{
						//����ѡ���Ƿ��ɱ��
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