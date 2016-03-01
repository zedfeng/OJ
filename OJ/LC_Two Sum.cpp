#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mapping;
		vector<int> result;
		unsigned int len = nums.size();
		for (int i = 0; i < len; i++) {
			mapping[nums[i]] = i;
		}
		for (int i = 0; i < len; i++) {
			int gap = target - nums[i];
			if (mapping.find(gap) != mapping.end() && mapping[gap]>i) {
				result.push_back(i);
				result.push_back(mapping[gap]);
				break;
			}
		}
		return result;
	}
};