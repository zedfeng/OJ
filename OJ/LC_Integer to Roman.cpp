#include<string>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string result;
		const string symbol[13] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		const int radix[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		for (int i = 0; i < 13; i++) {
			if (num >= radix[i]) {
				int count = num / radix[i];
				num %= radix[i];
				while (count != 0) {
					count--;
					result.append(symbol[i]);
				}
			}
		}
		return result;
	}
};