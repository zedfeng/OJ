#include<iostream>
using namespace std;
class Solution {
public:
	int climbStairs(int n) {
		//쳲��������е��ƹ�ʽ
		int prev = 1;
		int pprev = 1;
		int curr = 1;
		for (int i = 2; i <= n; i++){
			curr = prev + pprev;
			pprev = prev;
			prev = curr;
		}
		return curr;
	}
};