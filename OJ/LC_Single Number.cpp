#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int n = nums.size();
		int result = 0;
		for (int i = 0; i < n; i++){
			result ^= nums[i];
		}
		return result;
	}
};