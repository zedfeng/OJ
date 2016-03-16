#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> heights_stack;
		heights.push_back(0);	//dummy element
		int max_area = 0, area = 0;
		int n = heights.size();
		int i = 0;
		while (i<n) {
			if (heights_stack.empty() || heights[i]>heights[heights_stack.top()]) {
				heights_stack.push(i++);
			}
			else {
				int t = heights_stack.top();
				heights_stack.pop();
				area = heights[t] * (heights_stack.empty() ? i : (i - heights_stack.top() - 1));
				max_area = max_area > area ? max_area : area;
			}
		}
		return max_area;
	}
};