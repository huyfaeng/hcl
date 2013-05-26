#ifndef LEETCODE_LIST_HEAD
#define LEETCODE_LIST_HEAD

#include<stdarg.h>

#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//初始化链表
ListNode* init_list(int cnt, ...);

//反转链表
ListNode* reverse_list(ListNode* head, int end);

//释放链表的内存空间
void destory_list(ListNode* head);

#endif 