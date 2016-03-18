#include<vector>
#include<iterator>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		auto lower = lower_bound(nums.begin(), nums.end(), target);
		if (*lower == target){
			return distance(nums.begin(), lower);
		}
		else{
			return distance(nums.begin(), lower);
		}
	}
private:
	template<typename ForwardIterator, typename T>
	ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T target){
		while (first != last){
			auto mid = distance(first, last) / 2 + first;
			if (target > *mid){
				first = ++mid;
			}
			else{
				last = mid;
			}
		}
		return first;
	}
};