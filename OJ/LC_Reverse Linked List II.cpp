#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *prev = &dummy;
		for (int i = 1; i < m; i++){
			prev = prev->next;
		}
		ListNode *new_head = prev;
		prev = new_head->next;
		ListNode *cur = prev->next;
		for (int i = m; i < n; i++){
			prev->next = cur->next;
			cur->next = new_head->next;
			new_head->next = cur;
			cur = prev->next;
		}
		return dummy.next;
	}
};