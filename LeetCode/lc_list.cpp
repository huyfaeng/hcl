
#include "lc_list.h"
#include<stdarg.h>

#define NULL 0

//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};

ListNode* init_list(int cnt, ...)
{
	va_list val;
	va_start(val,cnt);

	ListNode* head = NULL;
	ListNode* prev_node = NULL;

	for(int i=0;i<cnt;++i)
	{
		int node_value = va_arg(val,int);
		ListNode* node = new ListNode(node_value);

		if(NULL == head)
		{
			head = node;
			prev_node = head;
		}
		else
		{
			prev_node->next = node;
			prev_node = node;
		}
	}

	va_end(val);
	return head;
}

//反转链表
ListNode* reverse_list(ListNode* head, int end)
{
	ListNode* ppre = head;
	ListNode* pnode = NULL;
	ListNode* ppost = NULL;
	int cur_node_index = 0;

	if(NULL != ppre && end>1)
	{
		pnode = ppre->next;
		cur_node_index = 1;
	}
	else
	{
		return NULL;
	}

	if(NULL != pnode)
	{
		ppost = pnode->next;
	}

	while((NULL != pnode) && (cur_node_index <end))
	{
		pnode->next = ppre;
		ppre = pnode;
		pnode = ppost;
		++cur_node_index;

		if(NULL != ppost)
		{
			ppost = ppost->next;
		}
	}
	return ppre;
}

//释放链表的内存空间
void destory_list(ListNode* head)
{
	ListNode* post_node = NULL;

	if(NULL != head->next)
	{
		post_node = head->next;
	}
	else
	{
		delete head;
		return;
	}

	while(NULL != post_node)
	{
		delete head;
		head = post_node;
		post_node = post_node->next;
	}
}