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
		const TreeNode *p = root;
		stack<const TreeNode *> s;
		while (!s.empty() || p != NULL){
			if (p != NULL){
				s.push(p);
				p = p->left;
			}
			else{
				p = s.top();
				if (p->right != NULL){
					p = p->right;
				}
				else{
					s.pop();
					result.push_back(p->val);
				}
			}
		}
		return result;
	}
};