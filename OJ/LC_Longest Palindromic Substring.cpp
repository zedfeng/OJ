#include<string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		const int n = s.length();
		size_t max_len = 1, start = 0;
		bool dp[n][n];
		fill_n(&dp[0][0], n*n, false);
		for (size_t i = 0; i < n; i++) {
			dp[i][i] = true;
			for (size_t j = 0; j < i; j++) {
				dp[j][i] = (s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1]));
				if (dp[j][i] && (i - j + 1) > max_len) {
					max_len = i - j + 1;
					start = j;
				}
			}
		}
		return s.substr(start, max_len);
	}
};