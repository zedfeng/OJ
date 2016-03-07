#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, bool> nums_map;
		for (auto i : nums) {
			nums_map[i] = false;
		}
		int result = 0;
		for (auto i : nums) {
			if (nums_map[i] == true) {
				continue;
			}
			int len = 1;
			nums_map[i] = true;
			//search from the consecutive elements of i
			for (int j = i + 1; nums_map.find(j) != nums_map.end(); j++) {
				nums_map[j] = true;
				len++;
			}
			for (int j = i - 1; nums_map.find(j) != nums_map.end(); j--) {
				nums_map[j] = true;
				len++;
			}
			result = result > len ? result : len;
		}
		return result;
	}
};