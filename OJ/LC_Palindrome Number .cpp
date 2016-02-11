class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0){
			return false;
		}
		int scale = 1;
		while (x / scale >= 10){
			scale *= 10;
		}
		while (x > 0){
			int left = x / scale;
			int right = x % 10;
			if (left != right){
				return false;
			}
			x = x%scale / 10;
			scale /= 100;
		}
		return true;
	}
};