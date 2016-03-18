#include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int min;
		int max;
		int max_profit = 0;
		int n = prices.size();
		if (n <= 1){
			return 0;
		}
		min = prices[0];
		max = prices[0];
		for (int i = 1; i<n; i++){
			if (prices[i]>prices[i - 1]){
				max = prices[i];
			}
			else{
				max_profit += max - min;
				max = min = prices[i];
			}
		}
		max_profit += max - min;
		return max_profit;
	}
};