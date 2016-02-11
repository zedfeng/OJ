#include<iostream>
#include<string>
using namespace std;
int main(){
	string whole, part;
	while (cin >> whole){
		if (whole == "#"){
			break;
		}
		cin >> part;
		int result = 0;
		int pos = 0;
		while ((pos = whole.find(part)) != -1){
			result++;
			whole = whole.substr(pos + part.length(), whole.length());
		}
		cout << result << endl;
	}
	return 0;
}