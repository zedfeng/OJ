#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1){
			return true;
		}
		int reach = 1;
		for (int i = 0; i < reach&&i < n; i++){
			reach = max(reach, nums[i] + i + 1);
		}
		return reach >= n;
	}
};