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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> stk;
		TreeNode *p = root, *prev = NULL;
		while (p != NULL || !stk.empty()) {
			if (p != NULL) {
				stk.push(p);
				p = p->left;
			}
			else {
				p = stk.top();
				if (p->right != NULL&&p->right != prev) {
					p = p->right;
				}
				else {
					result.push_back(p->val);
					stk.pop();
					prev = p;
					p = NULL;
				}
			}
		}
		return result;
	}
};