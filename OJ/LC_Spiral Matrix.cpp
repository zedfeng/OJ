#include<vector>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		if (matrix.empty()){
			return result;
		}
		int m = matrix.size();
		int n = matrix.front().size();
		int begin_x = 0, end_x = n - 1;
		int begin_y = 0, end_y = m - 1;
		while (true){
			for (int j = begin_x; j <= end_x; j++){
				result.push_back(matrix[begin_y][j]);
			}
			if (++begin_y > end_y){
				break;
			}
			for (int i = begin_y; i <= end_y; i++){
				result.push_back(matrix[i][end_x]);
			}
			if (begin_x > --end_x){
				break;
			}
			for (int j = end_x; j >= begin_x; j--){
				result.push_back(matrix[end_y][j]);
			}
			if (begin_y > --end_y){
				break;
			}
			for (int i = end_y; i >= begin_y; i--){
				result.push_back(matrix[i][begin_x]);
			}
			if (++begin_x > end_x){
				break;
			}
		}
		return result;
	}
};