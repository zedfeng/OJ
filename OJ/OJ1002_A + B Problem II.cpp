#include<iostream>
using namespace std;
const int LEN = 1000;
void addLargeInt(char* a, char* b, char* result);
int main(){
	int T;
	char a[LEN+1], b[LEN+1], result[LEN+2];
	cin >> T;
	for (int i = 1; i <= T; i++){
		cin >> a >> b;
		addLargeInt(a, b, result);
		cout << "Case " << i << ":" << endl;
		cout << a << " + " << b << " = " << result << endl;
		if (i < T){
			cout << endl;
		}
	}
}
void addLargeInt(char* a, char* b, char* result){
	int i = strlen(a)-1;
	int j = strlen(b)-1;
	int k = 0;
	int carry = 0;
	int temp[LEN + 1];
	while (i >= 0 || j >= 0){
		temp[k] = 0;
		temp[k] += carry;
		if (i >= 0){
			temp[k] += a[i--] - '0';
		}
		if (j >= 0){
			temp[k] += b[j--] - '0';
		}
		if (temp[k] >= 10){
			temp[k] -= 10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		k++;
	}
	if (carry == 1){
		temp[k] = 1;
	}
	else{
		k--;
	}
	for (i=0; k >= 0; k--,i++){
		result[i] = '0' + temp[k];
	}
	result[i] = '\0';
}