#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	bool containsDuplicate(vector<int>& nums) {
//		sort(nums.begin(), nums.end());
//		vector<int>::iterator resize_it = unique(nums.begin(), nums.end());
//		return resize_it != nums.end() ? true : false;
//	}
//};
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> nums_map;
		for (int i = 0; i < nums.size(); i++) {
			if (nums_map.find(nums[i]) != nums_map.end()) {
				return true;
			}
			nums_map[nums[i]]++;
		}
		return false;
	}
};