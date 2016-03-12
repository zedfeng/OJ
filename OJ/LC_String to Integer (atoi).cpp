#include<string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		auto scan = str.begin();
		int num = 0;
		int sign = 1;
		while (scan < str.end() && *scan == ' ') {
			scan++;
		}
		if (*scan == '+') {
			scan++;
		}
		else if (*scan == '-') {
			scan++;
			sign = -1;
		}
		while (scan < str.end()) {
			if (*scan<'0' || *scan>'9') {
				break;
			}
			if (num > INT_MAX / 10 || (num == INT_MAX / 10 && *scan - '0' > INT_MAX % 10)) {
				return sign == 1 ? INT_MAX : INT_MIN;
			}
			num *= 10;
			num += *scan - '0';
			scan++;
		}
		return num*sign;
	}
};