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
		if (head == NULL || head->next == NULL){
			return;
		}
		ListNode *prev = NULL, *slow, *fast;
		slow = head;
		fast = head;
		while (fast&&fast->next){
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = NULL;
		slow = reverse(slow);
		ListNode *curr = head;
		while (curr->next != NULL){
			ListNode *tmp = curr->next;
			curr->next = slow;
			slow = slow->next;
			curr->next->next = tmp;
			curr = tmp;
		}
		curr->next = slow;
		return;
	}
private:
	ListNode* reverse(ListNode* head){
		if (head == NULL || head->next == NULL){
			return head;
		}
		ListNode *prev, *curr, *next;
		for (prev = head, curr = head->next, next = curr->next; curr; prev = curr, curr = next, next = next ? next->next : NULL){
			curr->next = prev;
		}
		head->next = NULL;
		return prev;
	}
};