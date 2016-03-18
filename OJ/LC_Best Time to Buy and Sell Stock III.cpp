#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		return kth_max_profit(2, prices);
	}
private:
	int kth_max_profit(int k, vector<int> &prices) {
		int len = prices.size();
		if (len < 2) return 0;
		if (k > len / 2){ // simple case find all pairs that can make money
			int ans = 0;
			for (int i = 1; i < len; ++i){
				ans += max(prices[i] - prices[i - 1], 0);
			}
			return ans;
		}
		vector<int> hold(k + 1, INT_MIN);
		vector<int> rele(k + 1, 0);
		int cur;
		for (int i = 0; i < len; ++i){
			cur = prices[i];
			for (int j = k; j > 0; --j){
				rele[j] = max(rele[j], hold[j] + cur);
				hold[j] = max(hold[j], rele[j - 1] - cur);
			}
		}
		return rele[k];
	}
};