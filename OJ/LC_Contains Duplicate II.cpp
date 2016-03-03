#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> nums_map;
		for (int i = 0; i < nums.size(); i++) {
			unordered_map<int, int>::iterator pos_find = nums_map.find(nums[i]);
			if (pos_find != nums_map.end() && i - pos_find->second <= k) {
				return true;
			}
			else {
				nums_map[nums[i]] = i;
			}
		}
		return false;
	}
};