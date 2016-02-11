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
		const TreeNode *curr, *prev;
		stack<const TreeNode *> s;
		curr = root;
		do{
			while (curr != NULL){
				s.push(curr);
				curr = curr->left;
			}
			prev = NULL;
			while (!s.empty()){
				curr = s.top();
				s.pop();
				if (curr->right == prev){
					result.push_back(curr->val);
					prev = curr;
				}
				else{
					s.push(curr);
					curr = curr->right;
					break;
				}
			}
		} while (!s.empty());
		return result;
	}
};