class Solution {
public:
	int mySqrt(int x) {
		if (x < 2){
			return x;
		}
		int begin = 1;
		int end = x / 2;
		int mid;
		int last = 1;
		while (begin <= end){
			mid = begin + (end - begin) / 2;
			if (x / mid == mid){
				//mid*mid可能越界
				return mid;
			}
			else if (x / mid > mid){
				last = mid;
				begin = mid + 1;
			}
			else{
				end = mid - 1;
			}
		}
		return last;
	}
};