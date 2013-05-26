/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "lc_list.h"

class Solution_Rotate_List {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		ListNode* p_pre_ndoe = head;
		ListNode* p_post_node = head;
		int i=0;

		if(NULL == head)
		{
			return NULL;
		}

		//get the size of the list
		while(NULL !=	p_pre_ndoe)
		{
			++i;
			p_pre_ndoe = p_pre_ndoe->next;
		}

		k %= i;
		i = 0;
		p_pre_ndoe = head;
		 
		if(0 == k)
		{
			return head;
		} 

		while(NULL != p_post_node->next)
		{
			++i;
			if(i>k)
			{
				p_pre_ndoe = p_pre_ndoe->next;
			}
			p_post_node = p_post_node->next;
		}
        
		p_post_node->next = head;

		p_post_node = p_pre_ndoe->next;
		p_pre_ndoe->next = NULL;

		return p_post_node;
    }
};