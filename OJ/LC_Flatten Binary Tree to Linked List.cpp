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
	void flatten(TreeNode* root) {
		vector<TreeNode*> preorder_vec;
		preorderTraversal(root, preorder_vec);
		if (!root) {
			return;
		}
		TreeNode* p = root;
		for (auto scan = preorder_vec.begin() + 1; scan != preorder_vec.end(); ++scan) {
			p->left = NULL;
			p->right = *scan;
			p = p->right;
		}
	}
	void preorderTraversal(TreeNode* root, vector<TreeNode*>& vec) {
		if (!root) {
			return;
		}
		else {
			vec.push_back(root);
			preorderTraversal(root->left, vec);
			preorderTraversal(root->right, vec);
		}
	}
};