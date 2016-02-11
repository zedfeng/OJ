#include<iostream>
#include<algorithm>
using namespace std;
const int kMaxLen = 1001;
char str[kMaxLen];
int num[kMaxLen];
int main(){
	while (cin >> str){
		int i = 0;
		int j = 0;
		int p = 0;
		memset(num, 0, sizeof(num));
		int len = strlen(str) + 1;
		while (len--){
			while (str[j] == '5'){
				j++;
			}
			if ((str[i] == '5' || str[i] == '\0') && j < i){
				for (int k = j; k < i; k++){
					num[p] *= 10;
					num[p] += str[k] - '0';
				}
				p++;
				j = i;
			}
			i++;
		}
		sort(num, num + p);
		for (int i = 0; i < p - 1; i++){
			cout << num[i] << " ";
		}
		cout << num[p - 1] << endl;
	}
	return 0;
}