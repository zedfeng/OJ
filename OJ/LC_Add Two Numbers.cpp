#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy(-1);
		ListNode* prev = &dummy;
		int carry = 0;
		for (ListNode *p1 = l1, *p2 = l2; p1 != NULL || p2 != NULL; p1 = p1 == NULL ? NULL : p1->next, p2 = p2 == NULL ? NULL : p2->next, prev = prev->next){
			int num1 = p1 == NULL ? 0 : p1->val;
			int num2 = p2 == NULL ? 0 : p2->val;
			int value = (num1 + num2 + carry) % 10;
			carry = num1 + num2 + carry >= 10 ? 1 : 0;
			prev->next = new ListNode(value);
		}
		if (carry){
			prev->next = new ListNode(carry);
		}
		return dummy.next;
	}
};