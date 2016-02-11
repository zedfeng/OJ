#include<string>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		int len = a.length() > b.length() ? a.length() : b.length();
		string result;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int carry = 0;
		for (int i = 0; i < len; i++){
			int a_num = i < a.length() ? a[i] - '0' : 0;
			int b_num = i < b.length() ? b[i] - '0' : 0;
			int sum = a_num + b_num + carry;
			if (sum >= 2){
				sum %= 2;
				carry = 1;
			}
			else{
				carry = 0;
			}
			result.insert(result.begin(), sum + '0');
		}
		if (carry){
			result.insert(result.begin(), carry + '0');
		}
		return result;
	}
};