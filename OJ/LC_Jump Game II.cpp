#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int begin = 0;
		int end = 0;
		int step = 0;
		if (nums.size() <= 1){
			return 0;
		}
		while (begin <= end){
			++step;
			const int last_end = end;
			for (int i = begin; i <= last_end; i++){
				end = max(end, nums[i] + i);
				if (end >= nums.size() - 1){
					return step;
				}
			}
			begin = last_end + 1;
		}
		return 0;
	}
};