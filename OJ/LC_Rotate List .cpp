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
		//�����б�õ��䳤�ȣ�ע��k���ܴ����б��ȣ�����k%=len������β�ڵ�nextָ���׽ڵ㣬�γ�һ������Ȼ��ӵ�ǰλ����len-k%len���Ͽ������ǽ����
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