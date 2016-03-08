#include<vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		for (auto i = digits.rbegin(); i != digits.rend(); i++) {
			*i += carry;
			carry = *i / 10;
			*i %= 10;
		}
		if (carry) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};