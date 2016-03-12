#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string commonPrefix;
		if (strs.empty()) {
			return commonPrefix;
		}
		for (int i = 0; i < strs[0].size(); i++) {
			for (int j = 1; j < strs.size(); j++) {
				if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
					return commonPrefix;
				}
			}
			commonPrefix.push_back(strs[0][i]);
		}
		return commonPrefix;
	}
};