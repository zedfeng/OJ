#include<vector>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0){
			return 0;
		}
		int m = matrix.size();
		int n = matrix.front().size();
		vector<int> left_pos(n, 0);
		vector<int> right_pos(n, n);
		vector<int> max_height(n, 0);
		int result = 0;
		for (int i = 0; i < m; i++){
			int left = 0;
			int right = n;
			for (int j = 0; j < n; j++){
				if (matrix[i][j] == '1'){
					max_height[j]++;
					left_pos[j] = max(left_pos[j], left);
				}
				else{
					max_height[j] = 0;
					left_pos[j] = 0;
					right_pos[j] = n;
					left = j + 1;
				}
			}
			for (int j = n - 1; j >= 0; j--){
				if (matrix[i][j] == '1'){
					right_pos[j] = min(right_pos[j], right);
					result = max(result, max_height[j] * (right_pos[j] - left_pos[j]));
				}
				else{
					right = j;
				}
			}
		}
		return result;
	}
private:
	int max(int a, int b){
		return a > b ? a : b;
	}
	int min(int a, int b){
		return a > b ? b : a;
	}
};