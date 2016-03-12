#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		unordered_map<string, vector<string>> result_map;
		for (auto str : strs) {
			string key = str;
			sort(key.begin(), key.end());
			result_map[key].push_back(str);
		}
		for (auto it = result_map.begin(); it != result_map.end(); it++) {
			sort(it->second.begin(), it->second.end());
			result.push_back(it->second);
		}
		return result;
	}
};