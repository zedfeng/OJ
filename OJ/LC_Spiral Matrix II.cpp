#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {

		int begin = 0;
		int end = n - 1;
		int ele = 1;
		vector<int> vec(n, 0);
		vector<vector<int>> matrix(n, vec);
		while (begin < end){
			for (int j = begin; j < end; j++){
				matrix[begin][j] = ele++;
			}
			for (int i = begin; i < end; i++){
				matrix[i][end] = ele++;
			}
			for (int j = end; j > begin; j--){
				matrix[end][j] = ele++;
			}
			for (int i = end; i > begin; i--){
				matrix[i][begin] = ele++;
			}
			++begin;
			--end;
		}
		if (begin == end){
			matrix[begin][end] = ele;
		}
		return matrix;
	}
};