#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL || k == 0 || k == 1){
			return head;
		}
		ListNode *count = head;
		int len = 0;
		while (count != NULL){
			count = count->next;
			len++;
		}
		if (len < k){
			return head;
		}
		//至少有k个结点且k>=2
		//递归求解
		else{
			ListNode dummy(-1);
			dummy.next = head;
			ListNode *prev, *curr, *next;
			int num = k - 2;
			for (prev = &dummy, curr = dummy.next, next = curr->next; num >= 0; num--, next = curr->next){
				curr->next = next->next;
				next->next = prev->next;
				prev->next = next;
			}
			curr->next = reverseKGroup(next, k);
			return dummy.next;
		}
	}
};