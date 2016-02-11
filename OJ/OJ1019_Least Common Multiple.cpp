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
	//ע����x*y���ܻᳬ��int��Χ������Ҫ�ȳ��ٳ�
	return x%small ? x / small*y : y / small*x;
}
int main(){
	int n, m, num;
	cin >> n;
	while (n--){
		cin >> m;
		//��n��������С��������������������������С����������֮��������������ת��Ϊ��n-1��������С������
		int least_common_multiple = 1;
		while (m--){
			cin >> num;
			least_common_multiple = findLCM(least_common_multiple, num);
		}
		cout << least_common_multiple << endl;
	}
	return 0;
}