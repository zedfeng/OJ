#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result;
		if (n == 0) {
			result.push_back(0);
		}
		if (n > 0) {
			vector<int> half = grayCode(n - 1);
			result.insert(result.end(), half.begin(), half.end());
			reverse(half.begin(), half.end());
			int base = 1 << n - 1;
			for (int i = 0; i < half.size(); i++) {
				result.push_back(half[i] + base);
			}
		}
		return result;
	}
};