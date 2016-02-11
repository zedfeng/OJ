#include<iostream>
using namespace std;
long long count;
void hanoi(int, int, int, int);
void move(int, int, int);
/*
1����n�����ӣ���m==f[n-1]+1����m==2^(n-1)�����m���ƶ�����n������;
2��m>f[n-1]+1����m>2^(n-1)������n-1�����ӣ��ƶ�����Ϊm-2^(n-1)��
3��m<=f[n-1]��n������δ�ƶ�������n-1�����ӣ��ƶ�����Ϊm��
4�ظ�1,2,3��
��m���зֽ�õ���m=2^k1+2^k2+������+2^ks����k1>k2>������>ks��
���������ģ����̣����ǿ��Եõ�����m�ε��ƶ��̺ž���ks+1
*/
int main(){
	int n;
	long long m;
	while (cin >> n >> m){
		if (n == 0 && m == 0){
			break;
		}
		n = 1;
		while (!(m & 1)){
			m >>= 1;
			n++;
		}
		cout << n << endl;
		//hanoi(n, 1, 2, 3);
	}
	return 0;
}
void hanoi(int n, int a, int b, int c){
	if (n == 1){
		move(1, a, c);
	}
	else{
		hanoi(n - 1, a, c, b);
		move(n, a, c);
		hanoi(n - 1, b, a, c);
	}
	return;
}
void move(int n, int a, int b){
	cout << "Move disk No. " << n << " from " << a << " to " << b << endl;
}