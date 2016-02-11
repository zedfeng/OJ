#include<iostream>
#include<stack>
using namespace std;
const int kMaxLen = 1001;
static char str[kMaxLen];
int main(){
	int t;
	cin >> t;
	cin.get();
	while (t--){
		cin.getline(str, kMaxLen);
		int len = strlen(str);
		char* str_rev = new char[len + 1];
		stack<char> s;
		int j = 0;
		for (int i = 0; i < len + 1; i++){
			if (str[i] != ' '&&str[i] != '\0'){
				s.push(str[i]);
			}
			else{
				while (!s.empty()){
					str_rev[j++] = s.top();
					s.pop();
				}
				str_rev[j++] = ' ';
			}
		}
		str_rev[len] = '\0';
		cout << str_rev << endl;
		delete[] str_rev;
	}
	system("pause");
	return 0;
}