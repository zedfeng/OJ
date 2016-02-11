#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		int result = 0;
		stack<int> height_stack;
		height.push_back(0);
		for (int i = 0; i < height.size();){
			if (height_stack.empty() || height[i] > height[height_stack.top()]){
				height_stack.push(i++);
			}
			else{
				int tmp = height_stack.top();
				height_stack.pop();
				result = max(result, height[tmp] * (height_stack.empty() ? i : i - height_stack.top() - 1));
			}
		}
		return result;
	}
private:
	int max(int a, int b){
		return a > b ? a : b;
	}
};