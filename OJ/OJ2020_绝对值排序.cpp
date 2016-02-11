#include<iostream>
#include<cmath>
using namespace std;
const int kMaxLen = 101;
struct absnum{
	int num;
	int abs_num;
}data[kMaxLen];
void swap(absnum& a, absnum& b){
	absnum temp;
	temp = b;
	b = a;
	a = temp;
	return;
}
void qsort(absnum* data, int from, int to){
	if (from >= to){
		return;
	}
	int pivot = to;
	int i = from - 1;
	for (int j = from; j < to; j++){
		if (data[pivot].abs_num < data[j].abs_num){
			i++;
			swap(data[i], data[j]);
		}
	}
	swap(data[i + 1], data[to]);
	pivot = i + 1;
	qsort(data, from, pivot - 1);
	qsort(data, pivot + 1, to);
}
int main(){
	int n;
	while (cin >> n){
		if (n == 0){
			break;
		}
		for (int i = 0; i < n; i++){
			cin >> data[i].num;
			data[i].abs_num = abs(data[i].num);
		}
		qsort(data, 0, n - 1);
		for (int i = 0; i < n - 1; i++){
			cout << data[i].num << " ";
		}
		cout << data[n - 1].num << endl;
	}
	return 0;
}