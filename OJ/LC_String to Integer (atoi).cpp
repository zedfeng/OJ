#include<string>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		int i = 0;
		int result = 0;
		int sign = 1;
		while (str[i] == ' '&&i < str.length()){
			i++;
		}
		if (str[i] == '+'){
			i++;
		}
		else if (str[i] == '-'){
			sign = -1;
			i++;
		}
		for (; str[i] >= '0'&&str[i] <= '9'&&i<str.length(); i++){
			if (result>INT_MAX / 10 || result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10){
				return sign == -1 ? INT_MIN : INT_MAX;
			}
			result = result * 10 + str[i] - '0';
		}
		return sign*result;
	}
};