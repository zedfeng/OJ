#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool used[9];
		//检查行
		for (int i = 0; i < 9; ++i){
			fill(used, used + 9, false);
			for (int j = 0; j < 9; ++j){
				if (!isValid(board[i][j], used)){
					return false;
				}
			}
			//检查列
			fill(used, used + 9, false);
			for (int j = 0; j < 9; ++j){
				if (!isValid(board[j][i], used)){
					return false;
				}
			}
		}
		//检查块
		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j){
				fill(used, used + 9, false);
				for (int m = i * 3; m < i * 3 + 3; ++m){
					for (int n = j * 3; n < j * 3 + 3; ++n){
						if (!isValid(board[m][n], used)){
							return false;
						}
					}
				}
			}
		}
		return true;
	}
private:
	bool isValid(char ch, bool used[9]){
		if (ch == '.'){
			return true;
		}
		if (used[ch - '1']){
			return false;
		}
		return used[ch - '1'] = true;
	}
};