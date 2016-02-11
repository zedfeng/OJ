#include<string>
#include<stack>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> str_stack;
		string left = "([{";
		string right = ")]}";
		for (int i = 0; i < s.length(); i++){
			if (left.find(s[i]) != string::npos){
				str_stack.push(s[i]);
			}
			if (right.find(s[i]) != string::npos){
				if (!str_stack.empty() && left[right.find(s[i])] == str_stack.top()){
					str_stack.pop();
				}
				else{
					return false;
				}
			}
		}
		return str_stack.empty();
	}
};