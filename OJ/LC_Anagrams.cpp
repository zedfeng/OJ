#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<string> anagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> group;
		for (const auto &s : strs){
			string key = s;
			sort(key.begin(), key.end());
			group[key].push_back(s);
		}
		vector<string> result;
		for (auto it = group.cbegin(); it != group.end(); it++){
			if (it->second.size() > 1){
				result.insert(result.end(), it->second.begin(), it->second.end());
			}
		}
		return result;
	}
};