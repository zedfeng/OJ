#include<iostream>
using namespace std;
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		for (RandomListNode *curr = head; curr != NULL;){
			RandomListNode *node = new RandomListNode(curr->label);
			node->next = curr->next;
			curr->next = node;
			curr = node->next;
		}
		for (RandomListNode *curr = head; curr != NULL;){
			if (curr->random != NULL){
				curr->next->random = curr->random->next;
			}
			curr = curr->next->next;
		}
		RandomListNode dummy(-1);
		for (RandomListNode *curr = head, *copy = &dummy; curr != NULL;){
			copy->next = curr->next;
			curr->next = curr->next->next;
			curr = curr->next;
			copy = copy->next;
		}
		return dummy.next;
	}
};