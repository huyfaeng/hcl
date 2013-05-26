/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

#include "lc_tree.h"
#include <queue>
using namespace std;

class Solution_Recovery_BST {
public:
	TreeNode* get_prev_node(TreeNode* node)
	{
		if(NULL == node || NULL == node->left)
		{
			return NULL;
		}

		TreeNode* node_left = node->left;
		while(NULL != node_left->right)
		{
			node_left = node_left->right;
		}

		return node_left;
	}

	TreeNode* get_next_node(TreeNode* node)
	{
		if(NULL == node || NULL == node->right)
		{
			return NULL;
		}

		TreeNode* node_right = node->right;
		while(NULL != node_right->left)
		{
			node_right = node_right->left;
		}

		return node_right;
	}

	void recoverTree(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		queue<TreeNode*> que_node;
		TreeNode* node = NULL;

		TreeNode* nearst_left_node = NULL;
		TreeNode* nearst_right_node = NULL;

		TreeNode* nearst_left_node_parent = NULL;
		TreeNode* nearst_right_node_parent = NULL;


		que_node.push(root);
		while(!que_node.empty())
		{
			node = que_node.front();
			que_node.pop();
			if(NULL != node->left)
			{
				que_node.push(node->left);
			}

			if(NULL != node->right)
			{
				que_node.push(node->right);
			}

			//if(NULL == nearst_left_node)
			{
				nearst_left_node_parent = node;
				TreeNode* node_left = node->left;
				while(node_left != NULL)
				{
					if(node_left->val >node->val)
					{
						if(NULL != nearst_left_node)
						{
							swap(nearst_left_node->val, node_left->val);
							return;
						}

						nearst_left_node = node_left;
						break;
					}
					nearst_left_node_parent = node_left;
					node_left = node_left->right;
				}
			}

			//if(NULL == nearst_right_node)
			{
				nearst_right_node_parent = node;
				TreeNode* node_right = node->right;
				while(node_right != NULL)
				{
					if(node_right->val < node->val)
					{
						if(NULL != nearst_right_node)
						{
							swap(nearst_right_node->val, node_right->val);
							return;
						}

						nearst_right_node = node_right;
						break;
					}
					nearst_right_node_parent  = node_right;
					node_right = node_right->left;
				}
			}

			if(NULL != nearst_left_node && NULL != nearst_right_node)
			{
				swap(nearst_left_node->val,nearst_right_node->val);
				return;
			}
		}

		if(NULL != nearst_left_node && NULL == nearst_right_node)
		{
			swap(nearst_left_node->val,nearst_left_node_parent->val);
			return;
		}

		if(NULL != nearst_right_node && NULL == nearst_left_node)
		{
			swap(nearst_right_node->val,nearst_right_node_parent->val);
			return;
		}
	}
};