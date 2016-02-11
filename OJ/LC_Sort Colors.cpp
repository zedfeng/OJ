#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int i = 0, red = 0, blue = nums.size() - 1;
		while (i <= blue){
			if (nums[i] == 0){
				swap(nums[red++], nums[i++]);
			}
			else if (nums[i] == 2){
				swap(nums[blue--], nums[i]);
			}
			else
			{
				i++;
			}
		}
	}
};