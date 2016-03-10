#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode dummy(-1);
		dummy.next = head;
		//finish in one path
		ListNode *p = &dummy, *q = &dummy;
		while (n) {
			n--;
			q = q->next;
		}
		while (q->next) {
			p = p->next;
			q = q->next;
		}
		ListNode *tmp = p->next;
		p->next = p->next->next;
		delete tmp;
		return dummy.next;
	}
};