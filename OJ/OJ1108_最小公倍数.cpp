#include<iostream>
using namespace std;
int main(){
	int x, y;
	while (cin >> x >> y){
		//两数最大公约数与最小公倍数乘积等于两数乘积
		int large;
		int small;
		large = x > y ? x : y;
		small = x > y ? y : x;
		while (large%small != 0){
			int temp = large%small;
			large = small > temp ? small : temp;
			small = small > temp ? temp : small;
		}
		int greatest_common_divisor = small;
		int lowest_common_multiple = x*y / small;
		cout << lowest_common_multiple << endl;
	}
	return 0;
}