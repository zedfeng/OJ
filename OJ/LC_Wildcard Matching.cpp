#include<string>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		auto s_it = s.begin();
		auto p_it = p.begin();
		auto s_star = s.end();
		auto p_star = p.end();
		while (*s_it) {
			if (*s_it == *p_it || *p_it == '?') {
				++s_it;
				++p_it;
				continue;
			}
			else if (*p_it == '*') {
				s_star = s_it;
				p_star = p_it;
				++p_it;
				continue;
			}
			else if (*p_star) {
				//if there exists a * before, rematch the strings from the new beginnings.
				p_it = p_star + 1;
				s_it = ++s_star;
				continue;
			}
			return false;
		}
		while (*p_it == '*') {
			++p_it;
		}
		return !*p_it;
	}
};