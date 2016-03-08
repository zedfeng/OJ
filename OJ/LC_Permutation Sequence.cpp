#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string str(n, '0');
		string result = "";
		for (int i = 0; i < n; i++) {
			str[i] += i + 1;
		}
		//���б���
		int base = factorial(n - 1);
		int kth = k - 1;
		int pos = 0;
		for (int i = n - 1; i >= 0; i--) {
			pos = kth / base;
			result.push_back(str[pos]);
			str.erase(pos, 1);
			kth %= base;
			base = (i == 0) ? 1 : base / i;
		}
		return result;
	}
private:
	int factorial(int n) {
		int result = 1;
		for (int i = 1; i <= n; i++) {
			result *= i;
		}
		return result;
	}
};