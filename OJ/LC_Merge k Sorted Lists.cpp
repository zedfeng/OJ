#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0){
			return NULL;
		}
		else{
			return mergeSort(lists, 0, lists.size() - 1);
		}
	}
private:
	ListNode* mergeSort(vector<ListNode*>& lists, int begin, int end){
		if (end - begin == 0){
			return lists[begin];
		}
		else{
			int mid = (begin + end) / 2;
			ListNode *l1 = mergeSort(lists, begin, mid);
			ListNode *l2 = mergeSort(lists, mid + 1, end);
			return mergeTwoLists(l1, l2);
		}
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummy(-1);
		ListNode *curr = &dummy;
		while (l1 != NULL || l2 != NULL){
			if (l1 == NULL){
				curr->next = l2;
				l2 = NULL;
			}
			else if (l2 == NULL){
				curr->next = l1;
				l1 = NULL;
			}
			else if (l1->val < l2->val){
				curr->next = l1;
				curr = curr->next;
				l1 = l1->next;
			}
			else{
				curr->next = l2;
				curr = curr->next;
				l2 = l2->next;
			}
		}
		return dummy.next;
	}
};