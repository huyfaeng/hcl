#ifndef LEETCODE_LIST_HEAD
#define LEETCODE_LIST_HEAD

#include<stdarg.h>

#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//��ʼ������
ListNode* init_list(int cnt, ...);

//��ת����
ListNode* reverse_list(ListNode* head, int end);

//�ͷ�������ڴ�ռ�
void destory_list(ListNode* head);

#endif 