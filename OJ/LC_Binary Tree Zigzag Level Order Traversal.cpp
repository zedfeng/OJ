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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		zigzagLevelOrderTraversal(root, 1, result, true);
		return result;
	}
	void zigzagLevelOrderTraversal(TreeNode* root, int level, vector<vector<int>>& result, bool order) {
		if (root == NULL) {
			return;
		}
		if (level > result.size()) {
			result.push_back(vector<int>());
		}
		if (order) {
			result[level - 1].push_back(root->val);
		}
		else {
			result[level - 1].insert(result[level - 1].begin(), root->val);
		}
		zigzagLevelOrderTraversal(root->left, level + 1, result, !order);
		zigzagLevelOrderTraversal(root->right, level + 1, result, !order);
	}
};