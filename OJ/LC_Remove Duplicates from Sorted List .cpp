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
		ListNode dummy(-1);
		dummy.next = head;
		ListNode* prev;
		ListNode* curr;
		prev = dummy.next;
		curr = prev ? prev->next : NULL;
		while (curr != NULL) {
			if (curr->val == prev->val) {
				prev->next = curr->next;
				delete curr;
				curr = prev->next;
			}
			else {
				prev = prev->next;
				curr = prev->next;
			}
		}
		return dummy.next;
	}
};