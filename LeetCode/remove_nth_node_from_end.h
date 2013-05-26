/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "lc_list.h"

class Solution_Remove_Nth_Node_From_End {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(NULL == head || 0 == n)
		{
			return head;
		}

		int dist = 0;
		ListNode* ppre = NULL;
		ListNode* ppost = head;

		while(ppost->next != NULL)
		{
			ppost = ppost->next;
			++dist;

			if(dist>=n)
			{
				if(NULL == ppre)
				{
					ppre = head;
				}
				else
				{
					ppre = ppre->next;
				}
			}
		}

		if(n == dist+1)
		{
			return head->next;
		}
		
		if(NULL != ppre->next)
		{
			ppre->next = ppre->next->next; 
		}
		else
		{
			ppre->next = NULL;
		}
		return head;
    }
};