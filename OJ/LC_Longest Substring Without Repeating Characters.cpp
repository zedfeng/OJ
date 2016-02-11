#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int result = 0;
		int start = 0;
		const int ASCII_MAX = 128;
		int last[ASCII_MAX];
		fill(last, last + ASCII_MAX, -1);
		for (int i = 0; i < s.size(); i++){
			if (last[s[i] - NULL] >= start){
				result = max(result, i - start);
				start = last[s[i] - NULL] + 1;
			}
			last[s[i] - NULL] = i;
		}
		return max(result, (int)s.size() - start);
	}
};