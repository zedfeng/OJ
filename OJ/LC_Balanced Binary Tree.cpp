#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return balancedHeight(root) >= 0;
	}
	int balancedHeight(TreeNode* root) {
		if (!root) {
			return 0;
		}
		else {
			int left = balancedHeight(root->left);
			int right = balancedHeight(root->right);
			if (left < 0 || right < 0 || abs(left - right)>1) {
				return -1;
			}
			return max(left, right) + 1;
		}
	}
};