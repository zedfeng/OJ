#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		auto rfirst = nums.rbegin();
		auto target = next(rfirst);
		while (target != nums.rend() && *target >= *prev(target)) {
			target++;
		}
		if (target == nums.rend()) {
			reverse(nums.rbegin(), nums.rend());
		}
		else {
			auto target_next = nums.rbegin();
			while (target_next != nums.rend() && *target_next <= *target) {
				target_next++;
			}
			swap(*target, *target_next);
			reverse(nums.rbegin(), target);
		}
	}
};