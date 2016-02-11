#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		const size_t m = matrix.size();
		const size_t n = matrix[0].size();
		bool first_row_has_zero = false;
		bool first_col_has_zero = false;
		for (size_t i = 0; i < n; i++){
			if (matrix[0][i] == 0){
				first_row_has_zero = true;
				break;
			}
		}
		for (size_t i = 0; i < m; i++){
			if (matrix[i][0] == 0){
				first_col_has_zero = true;
				break;
			}
		}
		for (size_t i = 0; i < m; i++){
			for (size_t j = 0; j < n; j++){
				if (matrix[i][j] == 0){
					//标记需要最后设0的行列号
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}
		//除了第一行第一列，
		for (size_t i = 1; i < m; i++){
			for (int j = 1; j < n; j++){
				if (matrix[i][0] == 0 || matrix[0][j] == 0){
					matrix[i][j] = 0;
				}
			}
		}
		if (first_row_has_zero){
			for (size_t i = 0; i < n; i++){
				matrix[0][i] = 0;
			}
		}
		if (first_col_has_zero){
			for (size_t i = 0; i < m; i++){
				matrix[i][0] = 0;
			}
		}
	}
};