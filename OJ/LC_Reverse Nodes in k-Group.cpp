#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 0 || k == 1) {
			return head;
		}
		ListNode *end, *prev, *curr;
		end = head;
		for (int i = 0; i < k; i++) {
			if (end == NULL) {
				return head;
			}
			end = end->next;
		}
		prev = head;
		curr = prev->next;
		while (curr != end) {
			prev->next = curr->next;
			curr->next = head;
			head = curr;
			curr = prev->next;
		}
		prev->next = reverseKGroup(curr, k);
		return head;
	}
};