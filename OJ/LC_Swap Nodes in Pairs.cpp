#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *prev, *curr, *next;
		ListNode dummy(-1);
		dummy.next = head;
		for (prev = &dummy, curr = prev->next, next = curr ? curr->next : NULL; next; prev = curr, curr = curr->next, next = curr ? curr->next : NULL) {
			prev->next = next;
			curr->next = next->next;
			next->next = curr;
		}
		return dummy.next;
	}
};