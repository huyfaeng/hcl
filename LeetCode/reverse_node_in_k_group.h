#include "lc_list.h"


class Solution_Reverse_Node_In_K_Group {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(NULL == head || NULL == head->next || m==n)
		{
			return head;
		} 

		ListNode* pbegin = head;
		int i = 1;

		while(i<m-1 && NULL != pbegin)
		{
			pbegin = pbegin->next;
			++i;
		}

		//reverse
		ListNode* ppre = m>1?pbegin->next:head;
		ListNode* pnode = NULL;
		ListNode* ppost = NULL;
		int cur_node_index = 0;

		if(NULL != ppre && n-m>0)
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

		while((NULL != pnode) && (cur_node_index <= n-m))
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

		if(1==m)
		{
			head->next = pnode;
			return ppre;
		}
		else
		{
			
			pbegin->next->next = pnode;
			pbegin->next = ppre;
			return head;
		}

    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(NULL == head || k == 0)
		{
			return head;
		}

		//get size of list
		int len = 0;
		ListNode* ptmp = head;
		while(NULL != ptmp)
		{
			++len;
			ptmp = ptmp->next;
		}
		
		for(int start = 0;start+k<=len;start +=k)
		{
			head = reverseBetween(head,start+1,start+k);
		}

		return head;
    }
};



