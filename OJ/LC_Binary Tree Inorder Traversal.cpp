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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> stk;
		TreeNode* p = root;
		while (p != NULL || !stk.empty()) {
			if (p != NULL) {
				stk.push(p);
				p = p->left;
			}
			else {
				p = stk.top();
				stk.pop();
				result.push_back(p->val);
				p = p->right;
			}
		}
		return result;
	}
};