#include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0){
			return 0;
		}
		int max_profit = 0;
		vector<int> min_price(n, 0);
		min_price[0] = prices[0];
		for (int i = 1; i < n; i++){
			min_price[i] = min_price[i - 1] > prices[i] ? prices[i] : min_price[i - 1];
			max_profit = max_profit > prices[i] - min_price[i] ? max_profit : prices[i] - min_price[i];
		}
		return max_profit;
	}
};