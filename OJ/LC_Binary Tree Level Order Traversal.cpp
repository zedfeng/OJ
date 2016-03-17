#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		levelOrderTraversal(root, 1, result);
		return result;
	}
	void levelOrderTraversal(TreeNode* root, int level, vector<vector<int>>& result) {
		if (root == NULL) {
			return;
		}
		if (level > result.size()) {
			result.push_back(vector<int>());
		}
		result[level - 1].push_back(root->val);
		levelOrderTraversal(root->left, level + 1, result);
		levelOrderTraversal(root->right, level + 1, result);
	}
};