#include<string>
#include<stack>
using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
		int max_len = 0;
		int last = -1;
		int n = s.size();
		stack<int> left_par;
		for (int i = 0; i<n; ++i){
			if (s[i] == '('){
				left_par.push(i);
			}
			else{
				if (left_par.empty()){
					//not match
					last = i;
				}
				else{
					//match
					left_par.pop();
					if (left_par.empty()){
						//last not match element is ')'
						max_len = max_len>(i - last) ? max_len : i - last;
					}
					else{
						//last not match element is '('
						max_len = max_len > (i - left_par.top()) ? max_len : i - left_par.top();
					}
				}
			}
		}
		return max_len;
	}
};