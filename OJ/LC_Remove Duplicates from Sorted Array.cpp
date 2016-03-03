#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		vector<int>::iterator resize_it = unique(nums.begin(), nums.end());
//		int len = distance(nums.begin(), resize_it);
//		return len;
//	}
//};

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		for (int i = 0, j = i + 1; j < nums.size(); j++) {
			if (nums[j] != nums[i]) {
				nums[++i] = nums[j];
			}
			len = i + 1;
		}
		return len;
	}
};