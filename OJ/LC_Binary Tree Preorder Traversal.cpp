#include<stack>
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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> stk;
		TreeNode* p = root;
		if (root != NULL) {
			stk.push(root);
		}
		while (!stk.empty()) {
			p = stk.top();
			stk.pop();
			result.push_back(p->val);
			if (p->right) {
				stk.push(p->right);
			}
			if (p->left) {
				stk.push(p->left);
			}
		}
		return result;
	}
};