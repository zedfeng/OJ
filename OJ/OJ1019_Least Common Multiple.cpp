#include<iostream>
using namespace std;
int findLCM(int x, int y){
	int large, small;
	large = x > y ? x : y;
	small = x > y ? y : x;
	while (large%small != 0){
		int temp = large%small;
		large = temp > small ? temp : small;
		small = temp > small ? small : temp;
	}
	//注意用x*y可能会超过int范围，所以要先除再乘
	return x%small ? x / small*y : y / small*x;
}
int main(){
	int n, m, num;
	cin >> n;
	while (n--){
		cin >> m;
		//求n个数的最小公倍数，可先求任意两数的最小公倍数，用之代替这两个数，转化为求n-1个数的最小公倍数
		int least_common_multiple = 1;
		while (m--){
			cin >> num;
			least_common_multiple = findLCM(least_common_multiple, num);
		}
		cout << least_common_multiple << endl;
	}
	return 0;
}