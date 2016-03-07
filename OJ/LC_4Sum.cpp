#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		if (nums.size() < 4) {
			return result;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 3; i++) {
			for (int j = i + 1; j < nums.size() - 2; j++) {
				int k = j + 1, m = nums.size() - 1;
				while (k < m) {
					if (nums[k] + nums[m] == target - nums[i] - nums[j]) {
						vector<int> ans;
						ans.push_back(nums[i]);
						ans.push_back(nums[j]);
						ans.push_back(nums[k]);
						ans.push_back(nums[m]);
						result.push_back(ans);
						k++;
						m--;
					}
					else if (nums[k] + nums[m] < target - nums[i] - nums[j]) {
						k++;
					}
					else {
						m--;
					}
				}
			}
		}
		//drop duplicates, sort before unique (may cause time limit exceeded)
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};