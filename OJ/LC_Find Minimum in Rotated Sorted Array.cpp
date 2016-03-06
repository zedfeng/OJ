#include<vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int begin = 0, end = nums.size() - 1;
		while (begin < end) {
			int mid = (begin + end) / 2;	//while begin < end, we have mid < end and mid >= begin;
			if (nums[mid] < nums[end]) {
				end = mid;
			}
			else {
				begin = mid + 1;
			}
		}
		return nums[begin];
	}
};