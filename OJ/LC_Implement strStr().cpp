#include<string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) {
			return 0;
		}
		int m = haystack.length();
		int n = needle.length();
		for (int i = 0; i <= m - n; i++)
		{
			for (int j = 0; j <= n; j++) {
				if (j == n) {
					return i;
				}
				if (haystack[i + j] != needle[j]) {
					break;
				}
			}
		}
		return -1;
	}
};