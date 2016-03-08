#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		int n = ratings.size();
		vector<int> candy_num(n, 1);
		for (int i = 1, num = 1; i < n; i++) {
			if (ratings[i] > ratings[i - 1]) {
				num++;
				candy_num[i] = num > candy_num[i] ? num : candy_num[i];
			}
			else {
				num = 1;
			}
		}
		for (int i = n - 2, num = 1; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1]) {
				num++;
				candy_num[i] = num > candy_num[i] ? num : candy_num[i];
			}
			else {
				num = 1;
			}
		}
		/*
		template <class InputIterator, class T>
		T accumulate (InputIterator first, InputIterator last, T init);
		*/
		return accumulate(candy_num.begin(), candy_num.begin() + n, 0);
	}
};