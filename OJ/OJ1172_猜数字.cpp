#include<iostream>
using namespace std;
const int kMaxLen = 101;
bool findNum(int real_num, int test_num, int correct_num, int correct_pos){
	int real[4], test[4];
	int temp_correct_num = 0;
	int temp_correct_pos = 0;
	for (int i = 0; i < 4; i++){
		real[i] = real_num % 10;
		real_num /= 10;
		test[i] = test_num % 10;
		test_num /= 10;
		if (real[i] == test[i]){
			temp_correct_num++;
			temp_correct_pos++;
			real[i] = -1;
			test[i] = -2;
		}
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (real[i] == test[j]){
				temp_correct_num++;
				real[i] = -1;
				test[j] = -2;
			}
		}
	}
	return temp_correct_num == correct_num&&temp_correct_pos == correct_pos ? true : false;
}
int main(){
	int n, num[kMaxLen], correct_num[kMaxLen], correct_pos[kMaxLen];
	while (cin >> n){
		if (n == 0){
			break;
		}
		for (int i = 0; i < n; i++){
			cin >> num[i] >> correct_num[i] >> correct_pos[i];
		}
		bool find;
		int findSum = 0;
		int result = 0;
		for (int i = 1000; i < 10000; i++){
			find = true;
			for (int j = 0; j < n; j++){
				find = findNum(i, num[j], correct_num[j], correct_pos[j]);
				if (find == false){
					break;
				}
			}
			if (find == true){
				findSum++;
				result = i;
			}
		}
		if (findSum == 1){
			cout << result << endl;
		}
		else{
			cout << "Not sure" << endl;
		}
	}
	return 0;
}