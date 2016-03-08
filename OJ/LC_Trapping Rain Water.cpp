#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int water = 0;
		vector<int> left_max_height(height.size(), 0);
		vector<int> right_max_height(height.size(), 0);
		int left_max = 0, right_max = 0;
		//scan from left to right and record the left maximum height of bar i.
		for (int i = 0; i < height.size(); i++) {
			left_max_height[i] = i == 0 ? 0 : max(left_max_height[i - 1], height[i - 1]);
		}
		//scan from right to left and record the right maximum height of bar i.
		for (int i = height.size() - 1; i >= 0; i--) {
			right_max_height[i] = i == height.size() - 1 ? 0 : max(right_max_height[i + 1], height[i + 1]);
		}
		//get the water of each bar
		for (int i = 0; i < height.size(); i++) {
			water += max(min(left_max_height[i], right_max_height[i]) - height[i], 0);
		}
		return water;
	}
};