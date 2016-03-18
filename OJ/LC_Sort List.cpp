#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL){
			return NULL;
		}
		if (head->next == NULL){
			return head;
		}
		ListNode *prev = head;
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast != NULL&&fast->next != NULL){
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = NULL;
		ListNode *l1 = sortList(head);
		ListNode *l2 = sortList(slow);
		return mergeTwoSortList(l1, l2);
	}
private:
	ListNode* mergeTwoSortList(ListNode *l1, ListNode *l2){
		ListNode dummy(-1);
		ListNode *curr = &dummy;
		while (l1&&l2){
			if (l1->val < l2->val){
				curr->next = l1;
				l1 = l1->next;
			}
			else{
				curr->next = l2;
				l2 = l2->next;
			}
			curr = curr->next;
		}
		curr->next = l1 == NULL ? l2 : l1;
		return dummy.next;
	}
};