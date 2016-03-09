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
		ListNode *prev = &dummy, *curr = prev->next, *next = curr ? curr->next : NULL;
		int i = 1;
		while (i < m) {
			i++;
			prev = curr;
			curr = next;
			next = next ? next->next : NULL;
		}
		ListNode *beg = prev, *end = curr;
		i = m;
		while (i <= n) {
			i++;
			curr->next = prev;
			prev = curr;
			curr = next;
			next = next ? next->next : NULL;
		}
		beg->next = prev;
		end->next = curr;
		return dummy.next;
	}
};