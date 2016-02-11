#include<vector>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> sum(n, 0);
		int result = INT_MIN;
		sum[0] = nums[0];
		for (int i = 1; i < n; i++){
			if (sum[i - 1] > 0){
				sum[i] = sum[i - 1] + nums[i];
			}
			else{
				sum[i] = nums[i];
			}
		}
		for (int i = 0; i<n; i++){
			result = result>sum[i] ? result : sum[i];
		}
		return result;
	}
private:
	int max(int a, int b){
		return a > b ? a : b;
	}
};