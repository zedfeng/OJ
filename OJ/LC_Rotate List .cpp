#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode dummy(-1);
		dummy.next = head;
		if (head == NULL || k == 0) {
			return dummy.next;
		}
		int len = 1;
		while (head->next) {
			len++;
			head = head->next;
		}
		head->next = dummy.next;	//connect the end and the head of the list
		k = len - k%len;
		head = &dummy;
		while (k > 0) {
			k--;
			head = head->next;
		}
		dummy.next = head->next;
		head->next = NULL;
		return dummy.next;
	}
};