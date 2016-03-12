#include<string>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	int lengthOfLastWord(string s) {
//		auto first = find_if(s.rbegin(), s.rend(), ::isalpha);
//		auto last = find_if_not(first, s.rend(), ::isalpha);
//		return distance(first, last);
//	}
//};
class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0;
		auto str = s.begin(), end = prev(s.end());
		while (*end == ' ') {
			end--;
		}
		while (*str&&str <= end) {
			if (*str != ' ') {
				len++;
			}
			else {
				len = 0;
			}
			str++;
		}
		return len;
	}
};
