#include<string>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int result = 0;
		const string symbol[13] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		const int radix[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		int i = 0, index = 0;
		while (index < s.size() && i < 13) {
			string target = symbol[i];
			string curr = s.substr(index, target.size());
			if (curr == target) {
				result += radix[i];
				index += target.size();
			}
			else {
				i++;
			}
		}
		return result;
	}
};