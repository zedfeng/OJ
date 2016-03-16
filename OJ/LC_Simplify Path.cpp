#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> dirs;
		for (auto i = path.begin(); i < path.end(); i++) {
			auto j = find(i, path.end(), '/');
			auto dir = string(i, j);
			if (!dir.empty() && dir != ".") {
				if (dir == "..") {
					if (!dirs.empty()) {
						dirs.pop_back();
					}
				}
				else {
					dirs.push_back(dir);
				}
			}
			i = j;
		}
		string result;
		if (dirs.empty()) {
			result.push_back('/');
		}
		else {
			for (auto dir : dirs) {
				result.push_back('/');
				result.append(dir);
			}
		}
		return result;
	}
};