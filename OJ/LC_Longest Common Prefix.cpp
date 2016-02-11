#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()){
			return "";
		}
		for (int index = 0; index < strs[0].size(); index++){
			for (int i = 1; i < strs.size(); i++){
				if (strs[i][index] != strs[0][index]){
					return strs[0].substr(0, index);
				}
			}
		}
		return strs[0];
	}
};