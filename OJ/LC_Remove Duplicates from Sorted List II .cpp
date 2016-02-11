#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL){
			return head;
		}
		ListNode* curr = head->next;
		if (curr->val == head->val){
			while (curr != NULL&&curr->val == head->val){
				delete curr;
				curr = curr->next;
			}
			delete head;
			return deleteDuplicates(curr);
		}
		else{
			head->next = deleteDuplicates(curr);
			return head;
		}

	}
};