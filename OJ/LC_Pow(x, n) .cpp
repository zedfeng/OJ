#include<climits>
#include<cmath>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (fabs(x - 1.0) < 1e-6){
			return x;
		}
		else if (n < 0){
			//×¢ÒâÔ½½çn==INT_MIN
			double half = myPow(x, -n / 2);
			return 1.0 / (n % 2 ? half*half*x : half*half);
		}
		else if (n == 0){
			return 1.0;
		}
		else if (n == 1){
			return x;
		}
		else{
			double half = myPow(x, n / 2);
			return n % 2 ? half*half*x : half*half;
		}
	}
};