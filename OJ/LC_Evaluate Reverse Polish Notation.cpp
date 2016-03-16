#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int x, y;
		string op = "+-*/";
		stack<string> tokens_stack;
		for (auto str : tokens) {
			if (op.find(str) != string::npos) {
				x = stoi(tokens_stack.top());
				tokens_stack.pop();
				y = stoi(tokens_stack.top());
				tokens_stack.pop();
				if (str == "+") {
					tokens_stack.push(to_string(y + x));
				}
				else if (str == "-") {
					tokens_stack.push(to_string(y - x));
				}
				else if (str == "*") {
					tokens_stack.push(to_string(y * x));
				}
				else {
					tokens_stack.push(to_string(y / x));
				}
			}
			else {
				tokens_stack.push(str);
			}
		}
		return stoi(tokens_stack.top());
	}
};