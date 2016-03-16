#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> s_stack;
		int n = s.length();
		int result = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == ')' && !s_stack.empty() && s[s_stack.top()] == '(') {
				//if there is a match, pop the stack element.
				s_stack.pop();
				if (s_stack.empty()) {
					result = i + 1;
				}
				else {
					result = result > i - s_stack.top() ? result : i - s_stack.top();
				}
			}
			else {
				s_stack.push(i);
			}
		}
		return result;
	}
};