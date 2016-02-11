#include <iostream>
using namespace std;
int main(){
	int A, B, n;
	while (true){
		cin >> A >> B >> n;
		int num[50], t;
		if (!(A || B || n))
			break;
		else{
			//数字在0-6之间，相邻两数组合数为49，前50个数中必有重复对，由此求得周期。
			num[0] = num[1] = 1;
			for (int i = 2; i < 50; i++){
				num[i] = (A*num[i - 1] + B*num[i - 2]) % 7;
				if (num[i] == num[1] && num[i - 1] == num[0])
					t = i - 1;
			}
			cout << num[(n - 1) % t] << endl;
		}
	}
	return 0;
}