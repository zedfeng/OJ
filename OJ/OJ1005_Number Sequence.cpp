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
			//������0-6֮�䣬�������������Ϊ49��ǰ50�����б����ظ��ԣ��ɴ�������ڡ�
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