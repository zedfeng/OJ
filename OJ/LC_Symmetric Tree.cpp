#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		return root ? isSymmetricSub(root->left, root->right) : true;
	}
	bool isSymmetricSub(TreeNode* left, TreeNode* right) {
		if (!left&&!right) {
			return true;
		}
		else if (left&&right&&left->val == right->val) {
			return isSymmetricSub(left->left, right->right) && isSymmetricSub(left->right, right->left);
		}
		else {
			return false;
		}
	}
};