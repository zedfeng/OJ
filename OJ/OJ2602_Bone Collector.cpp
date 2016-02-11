#include <cstdio>
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
const int LEN = 1002;
//total[i][j]��¼����i����Ʒ����Ϊj�ı�������ֵ��
int val[LEN], vol[LEN], total[LEN][LEN];
int max(int x, int y){
	return x > y ? x : y;
}
int main(){
	int T, N, V;
	cin >> T;
	for (int i = 1; i <= T; i++){
		cin >> N >> V;
		for (int i = 1; i <= N; i++){
			cin >> val[i];
		}
		for (int i = 1; i <= N; i++){
			cin >> vol[i];
		}
		int maxVal = INT_MIN;
		memset(total, 0, sizeof(total));
		for (int i = 1; i <= N; i++){
			for (int j = 0; j <= V; j++){
				if (vol[i] > j){
					//�����i�������ȱ����ݻ���ֻ�ܷ�����
					total[i][j] = total[i - 1][j];
				}
				else{
					//����װ�£��Ƚ�װ�Ͳ�װ�ĸ�����š�
					total[i][j] = max(total[i - 1][j - vol[i]] + val[i], total[i - 1][j]);
				}
			}
		}
		cout << total[N][V] << endl;
	}
}