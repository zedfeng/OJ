#include<iostream>
using namespace std;
int main(){
	int N, a, b;
	cin >> N;
	while (N>0){
		cin >> a >> b;
		cout << a + b << endl;
		N--;
	}
	return 0;
}