#include<vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		bool find = false;
		if (matrix.size() == 0){
			return find;
		}
		const size_t m = matrix.size();
		const size_t n = matrix.front().size();
		int first = 0;
		int last = m*n;
		while (first != last){
			int mid = (first + last) / 2;
			if (target > matrix[mid / n][mid%n]){
				first = ++mid;
			}
			else{
				last = mid;
			}
		}
		if (first == m*n || matrix[first / n][first%n] != target){
			return false;
		}
		else{
			return true;
		}
	}
};