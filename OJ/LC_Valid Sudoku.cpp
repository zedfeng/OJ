#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		//check size
		if (board.size() != 9 || board[0].size() != 9) {
			return false;
		}
		//check column
		for (int i = 0; i < board.size(); i++) {
			vector<bool> check(board.size(), false);
			for (int j = 0; j < board.size(); j++) {
				if (!isdigit(board[j][i])) {
					continue;
				}
				int k = board[j][i] - '0';
				if (k == 0 || check[k - 1]) {
					return false;
				}
				check[k - 1] = true;
			}
		}
		//check row
		for (int i = 0; i < board.size(); i++) {
			vector<bool> check(board.size(), false);
			for (int j = 0; j < board.size(); j++) {
				if (!isdigit(board[i][j])) {
					continue;
				}
				int k = board[i][j] - '0';
				if (k == 0 || check[k - 1]) {
					return false;
				}
				check[k - 1] = true;
			}
		}
		//check block
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int row = i * 3;
				int col = j * 3;
				vector<bool> check(board.size(), false);
				for (int m = row; m < row + 3; m++) {
					for (int n = col; n < col + 3; n++) {
						if (!isdigit(board[m][n])) {
							continue;
						}
						int k = board[m][n] - '0';
						if (k == 0 || check[k - 1]) {
							return false;
						}
						check[k - 1] = true;
					}
				}
			}
		}
		return true;
	}
};