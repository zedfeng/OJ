#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	void reorderList(ListNode* head) {
		ListNode *slow, *fast, *prev, *next;
		slow = head;
		fast = head;
		prev = head;
		next = NULL;
		while (fast&&fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		next = slow ? slow->next : NULL;
		if (next) {
			slow->next = NULL;
			next = reverseList(next);
			ListNode* tmp;
			while (next) {
				tmp = prev->next;
				prev->next = next;
				next = next->next;
				prev->next->next = tmp;
				prev = tmp;
			}
		}
	}
	ListNode* reverseList(ListNode* head) {
		ListNode *prev, *curr;
		for (prev = head, curr = prev ? prev->next : NULL; curr; curr = prev->next) {
			prev->next = curr->next;
			curr->next = head;
			head = curr;
		}
		return head;
	}
};