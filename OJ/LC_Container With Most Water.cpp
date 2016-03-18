#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int begin = 0;
		int end = height.size() - 1;
		int result = INT_MIN;
		while (begin < end){
			int area = min(height[begin], height[end])*(end - begin);

			result = max(result, area);
			if (height[begin] <= height[end]){
				begin++;
			}
			else{
				end--;
			}
		}
		return result;
	}
};