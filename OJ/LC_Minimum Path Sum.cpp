#include<vector>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid.front().size();
		vector<int> vec(n, 0);
		vector<vector<int>> result(m, vec);
		result[0][0] = grid[0][0];
		for (int i = 1; i < n; i++){
			result[0][i] = result[0][i - 1] + grid[0][i];
		}
		for (int j = 1; j < m; j++){
			result[j][0] = result[j - 1][0] + grid[j][0];
		}
		for (int i = 1; i < m; i++){
			for (int j = 1; j < n; j++){
				result[i][j] = min(result[i - 1][j], result[i][j - 1]) + grid[i][j];
			}
		}
		return result[m - 1][n - 1];
	}
private:
	int min(int a, int b){
		return a < b ? a : b;
	}
};