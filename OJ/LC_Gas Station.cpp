#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int cur_sum = 0;
		int total = 0;
		int pos = 0;
		for (int i = 0; i < n; i++){
			cur_sum += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if (cur_sum < 0){
				cur_sum = 0;
				pos = (i + 1) % n;
			}
		}
		return total >= 0 ? pos : -1;
	}
};