#include<vector>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int begin = 0, end = nums.size() - 1;
		while (begin <= end) {
			int mid = (begin + end) / 2;
			if (nums[mid] == target) {
				return true;
			}
			else {
				if (nums[mid] < nums[end]) {
					if (target > nums[mid] && target <= nums[end]) {
						begin = mid + 1;
					}
					else {
						end = mid - 1;
					}
				}
				else if (nums[mid] > nums[end]) {
					if (target < nums[mid] && target >= nums[begin]) {
						end = mid - 1;
					}
					else {
						begin = mid + 1;
					}
				}
				else {	//nums[mid] == nums[end] && nums[mid] != target
					end--;	//drop the useless duplicates
				}
			}
		}
		return false;
	}
};