#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *fast, *slow, *new_slow;
		fast = head;
		slow = head;
		while (fast&&fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				new_slow = head;
				while (new_slow != slow) {
					new_slow = new_slow->next;
					slow = slow->next;
				}
				return new_slow;
			}
		}
		return NULL;
	}
};