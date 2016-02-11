#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		int water = 0;
		int len = height.size();
		int *max_left = new int[len];
		int *max_right = new int[len];
		max_left[0] = 0;
		max_right[len - 1] = 0;
		for (int i = 1; i < len; i++){
			max_left[i] = max_left[i - 1] > height[i - 1] ? max_left[i - 1] : height[i - 1];
			max_right[len - i - 1] = max_right[len - i] > height[len - i] ? max_right[len - i] : height[len - i];
		}
		for (int i = 1; i < len - 1; i++){
			int bar = max_left[i] > max_right[i] ? max_right[i] : max_left[i];
			if (height[i] < bar){
				water += bar - height[i];
			}
		}
		delete[] max_left;
		delete[] max_right;
		return water;
	}
};