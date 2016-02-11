#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	while (getline(cin, str)){
		if (str == "ENDOFINPUT"){
			break;
		}
		if (str == "START" || str == "END"){
			continue;
		}
		for (int i = 0; i < str.size(); i++){
			if (str[i] - 'A' >= 0 && str[i] - 'A' < 26){
				str[i] = str[i] - 'A' - 5 >= 0 ? str[i] - 5 : str[i] - 5 + 26;
			}
		}
		cout << str << endl;
	}
	return 0;
}