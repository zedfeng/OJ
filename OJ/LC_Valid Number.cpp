#include<string>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		int n = s.length();
		enum InputType {
			INVALID,	//0
			SPACE,		//1
			SIGN,		//2
			DIGIT,		//3
			DOT,		//4
			EXPONENT,	//5
			TYPE_NUM	//6
		};
		const int transitionTable[][TYPE_NUM] = {
			-1,0,2,3,4,-1,		//0, space, no valid number before
			-1,1,-1,-1,-1,-1,	//1, space, with valid number, valid state
			-1,-1,-1,3,4,-1,	//2, sign, no valid number before	
			-1,1,-1,3,5,6,		//3, digit, no exp, no dot before, valid state
			-1,-1,-1,5,-1,-1,	//4, dot, no valid number before 
			-1,1,-1,5,-1,6,		//5, dot, with valid number, valid state
			-1,-1,7,8,-1,-1,	//6, exp, nosign, no valid number behind
			-1,-1,-1,8,-1,-1,	//7, exp, with sign behind
			-1,1,-1,8,-1,-1,	//8, exp, with valid number behind, valid state
		};
		int state = 0;
		for (int i = 0; i < n; i++) {
			InputType input = INVALID;
			if (s[i] == ' ') {
				input = SPACE;
			}
			else if (s[i] == '+' || s[i] == '-') {
				input = SIGN;
			}
			else if (isdigit(s[i])) {
				input = DIGIT;
			}
			else if (s[i] == '.') {
				input = DOT;
			}
			else if (s[i] == 'e' || s[i] == 'E') {
				input = EXPONENT;
			}
			state = transitionTable[state][input];
			if (state == -1) {
				return false;
			}
		}
		return state == 1 || state == 3 || state == 5 || state == 8;
	}
};