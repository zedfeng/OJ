#include<iostream>
using namespace std;
long long count;
void hanoi(int, int, int, int);
void move(int, int, int);
/*
1考虑n号盘子，若m==f[n-1]+1，即m==2^(n-1)，则第m次移动的是n号盘子;
2若m>f[n-1]+1，即m>2^(n-1)，则考虑n-1号盘子，移动次数为m-2^(n-1)；
3若m<=f[n-1]，n号盘子未移动，考虑n-1号盘子，移动次数为m；
4重复1,2,3；
将m进行分解得到：m=2^k1+2^k2+。。。+2^ks；（k1>k2>。。。>ks）
经过上面的模拟过程，我们可以得到：第m次的移动盘号就是ks+1
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