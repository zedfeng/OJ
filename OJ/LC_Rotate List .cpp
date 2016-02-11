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
		if (head == NULL || k == 0){
			return head;
		}
		int len = 1;
		ListNode* curr = head;
		//遍历列表得到其长度，注意k可能大于列表长度，故令k%=len，将结尾节点next指向首节点，形成一个环，然后从当前位置跑len-k%len步断开，就是结果。
		while (curr->next != NULL){
			curr = curr->next;
			len++;
		}
		curr->next = head;
		k = len - k%len;
		//1<=k<=len
		while (k != 0){
			curr = curr->next;
			k--;
		}
		head = curr->next;
		curr->next = NULL;
		return head;
	}
};