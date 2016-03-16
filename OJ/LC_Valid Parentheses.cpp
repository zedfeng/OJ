#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		string left = "([{";
		string right = ")]}";
		stack<char> s_stack;
		for (auto c : s) {
			if (left.find(c) != string::npos) {
				s_stack.push(c);
			}
			else {
				if (s_stack.empty() || s_stack.top() != left[right.find(c)]) {
					return false;
				}
				else {
					s_stack.pop();
				}
			}
		}
		return s_stack.empty();
	}
};