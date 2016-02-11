#include<iostream>
#include<climits>
using namespace std;
int factorial(int n){
	int num = 1;
	for (int i = 1; i <= n; i++){
		num *= i;
	}
	return num;
}
int main(){
	unsigned int num = 1, sum, temp;
	while (num <= 2999999){
		temp = num;
		sum = 0;
		while (temp > 0){
			sum += factorial(temp % 10);
			temp /= 10;
		}
		if (sum == num){
			cout << num << endl;
		}
		num++;
	}
	return 0;
}