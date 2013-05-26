
#include "lc_tree.h"
#include <stdarg.h>
#include <queue>

using namespace std;

TreeNode* init_tree(int cnt, ...)
{	
	if(0 == cnt)
	{
		return NULL;
	}

	va_list val;
	va_start(val,cnt);

	queue<TreeNode*> que_node;

	TreeNode* root = new TreeNode(va_arg(val,int));
	TreeNode* parent = root;
	TreeNode* node = NULL;

	for(int i=1;i<cnt;++i)
	{
		int node_value = va_arg(val,int);
		TreeNode* node = new TreeNode(node_value);

		if(parent->left == NULL)
		{
			parent->left = node;
		}
		else if(parent->right == NULL)
		{
			parent->right = node;
			if( parent->left->val == (int)'#')
			{
				delete parent->left;
				parent->left = NULL;
			}

			while(!que_node.empty())
			{
				parent = que_node.front();
				que_node.pop();

				if(parent->val != '#')
				{
					break;
				}
			}
		}
		que_node.push(node);
	}

	va_end(val);
	return root;
}

void destory_tree(TreeNode* root)
{
	queue<TreeNode*> que_node;
	TreeNode* node = NULL;

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

		delete node;
	}
}

bool is_same_tree(TreeNode* left_node, TreeNode* right_node)
{
	if(NULL == left_node && NULL == right_node)
	{
		return true;
	}
	else if(NULL == left_node && NULL != right_node)
	{
		return false;
	}
	else if(NULL != left_node && NULL == right_node)
	{
		return false;
	}

	queue<TreeNode*> que_left;
	TreeNode* left_node_tmp = left_node;

	queue<TreeNode*> que_right;
	TreeNode* right_node_tmp = right_node;

	que_left.push(left_node_tmp);
	que_right.push(right_node_tmp);

	while(!que_left.empty() && !que_right.empty())
	{
		left_node_tmp = que_left.front();
		right_node_tmp = que_right.front();

		que_left.pop();
		que_right.pop();

		if(left_node_tmp->val != right_node_tmp->val)
		{
			return false;
		}

		if(NULL != left_node_tmp->left)
		{
			que_left.push(left_node_tmp->left);
		}

		if(NULL != left_node_tmp->right)
		{
			que_left.push(left_node_tmp->right);
		}

		if(NULL != right_node_tmp->left)
		{
			que_right.push(right_node_tmp->left);
		}

		if(NULL != right_node_tmp->right)
		{
			que_right.push(right_node_tmp->right);
		}
	}
	return true;
}

TreeNode* get_prev_node(TreeNode* root)
{
	return NULL;	
}

TreeNode* get_next_node(TreeNode* root)
{
	return NULL;
}