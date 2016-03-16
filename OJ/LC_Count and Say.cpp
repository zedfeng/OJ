#include<string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string result = "1";
		for (int i = 1; i < n; i++) {
			string temp = result;
			result = "";
			int count = 1;
			auto prev = temp.begin();
			for (auto scan = prev + 1; scan <= temp.end(); scan++) {
				if (*scan == *prev) {
					count++;
				}
				else {
					result += to_string(count);
					result.push_back(*prev);
					prev = scan;
					count = 1;
				}
			}
		}
		return result;
	}
};