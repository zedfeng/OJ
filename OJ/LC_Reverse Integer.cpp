#include<math.h>
#include <climits>
class Solution {
public:
	int reverse(int x) {
		int result = 0;
		while (x != 0){
			if (abs(result) > INT_MAX / 10)
				return 0;
			result = result * 10 + x % 10;
			x /= 10;
		}
		return result;
	}
};