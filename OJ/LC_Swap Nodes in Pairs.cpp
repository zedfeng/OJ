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
		ListNode *prev, *curr;
		ListNode dummy(-1);
		dummy.next = head;
		prev = &dummy;
		curr = prev->next;
		while (curr != NULL&&curr->next != NULL){
			prev->next = curr->next;
			prev = prev->next;
			curr->next = prev->next;
			prev->next = curr;
			prev = prev->next;
			curr = curr->next;
		}
		return dummy.next;
	}
};