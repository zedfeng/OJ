#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size() < 3) {
			return result;
		}
		int target = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				//drop duplicates
				continue;
			}
			int j = i + 1, k = nums.size() - 1;
			while (j < k) {
				if (nums[j] + nums[k] == target - nums[i]) {
					vector<int> ans;
					ans.push_back(nums[i]);
					ans.push_back(nums[j]);
					ans.push_back(nums[k]);
					result.push_back(ans);
					j++;
					k--;
					while (nums[j] == nums[j - 1] && j < k) {
						j++;
						//drop duplicates
					}	
					while (nums[k] == nums[k + 1] && j < k) {
						k--;
						//drop duplicates
					}	
				}
				else if (nums[j] + nums[k] < target - nums[i]) {
					j++;
				}
				else {
					k--;
				}
			}
		}
		//or drop duplicates by using (may cause time limit exceeded)
		//sort(result.begin(), result.end());
		//result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};