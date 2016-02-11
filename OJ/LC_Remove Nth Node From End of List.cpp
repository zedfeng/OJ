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
		ListNode *p, *q;
		p = &dummy;
		q = &dummy;
		while (n != 0){
			q = q->next;
			n--;
		}
		while (q->next != NULL){
			p = p->next;
			q = q->next;
		}
		ListNode *del = p->next;
		p->next = del->next;
		delete del;
		return dummy.next;
	}
};