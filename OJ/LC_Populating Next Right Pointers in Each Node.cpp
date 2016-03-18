#include<iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
	void connect(TreeLinkNode *root) {
		while (root) {
			TreeLinkNode *next_level = NULL, *prev_node = NULL;
			while (root) {
				if (!next_level) {
					next_level = root->left ? root->left : root->right;
				}
				if (root->left) {
					if (prev_node) {
						prev_node->next = root->left;
					}
					prev_node = root->left;
				}
				if (root->right) {
					if (prev_node) {
						prev_node->next = root->right;
					}
					prev_node = root->right;
				}
				root = root->next;
			}
			root = next_level;
		}
	}
};