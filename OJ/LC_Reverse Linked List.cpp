#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode *prev, *curr, *next;
		for (prev = head, curr = prev->next, next = curr->next; curr; prev = curr, curr = next, next = next ? next->next : NULL) {
			curr->next = prev;
		}
		head->next = NULL;
		return prev;
	}
};