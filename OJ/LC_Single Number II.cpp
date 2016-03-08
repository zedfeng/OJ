#include<vector>
using namespace std;

//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		int n = nums.size();
//		int result = 0;
//		const int width = sizeof(int) * 8;
//		int count[width];
//		fill_n(count, width, 0);
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < width; j++) {
//				count[j] += (nums[i] >> j) & 1;
//				count[j] %= 3;
//			}
//		}
//		for (int j = 0; j < width; j++) {
//			result += (count[j] << j);
//		}
//		return result;
//	}
//};
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int n = nums.size();
		int ones = 0, twos = 0, threes = 0;
		for (int i = 0; i < n; i++) {
			twos |= (ones&nums[i]);
			ones ^= nums[i];
			threes = ones&twos;
			twos &= ~threes;
			ones &= ~threes;
		}
		return ones;
	}
};