#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		int occur = 2;
		//can be used for n duplicates. 
		for (int i = occur - 1, j = i + 1; j < nums.size(); j++) {
			if (nums[j] != nums[i - occur + 1]) {
				nums[++i] = nums[j];
			}
			//else nums[j] is invalid duplicates, skip. (since sorted array, if nums[j] == nums[i - occur + 1], then nums[j] == nums[i] == ... == nums[i - occur + 1])
			len = i + 1;
		}
		return len;
	}
};