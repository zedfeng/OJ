#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<string> num_stack;
		for (auto token : tokens){
			if (is_operator(token)){
				int y = stoi(num_stack.top());
				num_stack.pop();
				int x = stoi(num_stack.top());
				num_stack.pop();
				int result = 0;
				if (token[0] == '+'){
					result = x + y;
				}
				else if (token[0] == '-'){
					result = x - y;
				}
				else if (token[0] == '*'){
					result = x*y;
				}
				else{
					result = x / y;
				}
				num_stack.push(to_string(result));
			}
			else{
				num_stack.push(token);
			}
		}
		return stoi(num_stack.top());
	}
private:
	bool is_operator(string& op){
		string op_str = "+-*/";
		return op.size() == 1 && op_str.find(op) != string::npos;
	}
};