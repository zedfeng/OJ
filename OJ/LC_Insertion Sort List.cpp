#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode dummy(-1);
		ListNode *curr = &dummy;
		while (head != NULL){
			ListNode *prev = head;
			head = head->next;
			curr = &dummy;
			while (curr->next != NULL&&curr->next->val < prev->val){
				curr = curr->next;
			}
			if (curr->next != NULL){
				prev->next = curr->next;
				curr->next = prev;
			}
			else{
				prev->next = NULL;
				curr->next = prev;
			}
		}
		return dummy.next;
	}
};