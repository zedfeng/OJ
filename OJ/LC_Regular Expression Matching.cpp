#include<string>
using namespace std;

class Solution {
public:
	bool recursiveIsMatch(string::iterator s, string::iterator p) {
		if (*p == '\0') {
			return *s == '\0';
		}
		if (*(p + 1) != '*') {
			return ((*p == *s) || (*p == '.'&&*s != '\0')) && recursiveIsMatch(s + 1, p + 1);
		}
		while ((*p == *s) || (*p == '.'&&*s != '\0')) {
			if (recursiveIsMatch(s, p + 2)) {
				return true;
			}
			s++;
		}
		return recursiveIsMatch(s, p + 2);
	}
	bool isMatch(string s, string p) {
		return recursiveIsMatch(s.begin(), p.begin());
	}
};