#include<vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int begin = 0, end = nums.size() - 1;
		while (begin <= end) {
			int mid = (begin + end) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			else {	//nums[mid] != target
				if (nums[mid] < nums[end]) {
					if (target > nums[mid] && target <= nums[end]) {
						begin = mid + 1;
					}
					else {
						end = mid - 1;
					}
				}
				else {
					if (target >= nums[begin] && target < nums[mid]) {
						end = mid - 1;
					}
					else {
						begin = mid + 1;
					}
				}
			}
		}
		return -1;
	}
};