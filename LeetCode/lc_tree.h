
#ifndef LEET_CODE_TREE_NODE_H
#define LEET_CODE_TREE_NODE_H

#define NULL 0

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* init_tree(int cnt, ...);

bool is_same_tree(TreeNode* left_node, TreeNode* right_node);

TreeNode* get_prev_node(TreeNode* root);

TreeNode* get_next_node(TreeNode* root);

void destory_tree(TreeNode* root);

#endif