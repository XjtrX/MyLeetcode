/*
author: jtr@BNU
date: 14.9.4
problem:
Populating Next Right Pointers in Each Node Total Accepted: 22806 Total Submissions: 64568 My Submissions
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/
#include "myIncs.h"

struct TreeLinkNode {
  	int val;
  	TreeLinkNode *left, *right, *next;
  	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root)
{
	if(root == NULL) return;
	queue<TreeLinkNode *> Q;
	Q.push(root);
	Q.push(NULL);
	TreeLinkNode *cur;
	while(!Q.empty())
	{
		cur = Q.front();
		Q.pop();
		if(cur == NULL) Q.push(NULL);
		while(!Q.empty() && cur == NULL )
		{
			cur = Q.front();
			Q.pop();
		}
		if(cur == NULL) return;
		Q.push(cur->left);
		Q.push(cur->right);
		cur->next = Q.front();
	}
}

int main(int argc, char const *argv[])
{
	TreeLinkNode *head = new TreeLinkNode(1);
	head->left = new TreeLinkNode(2);
	head->right = new TreeLinkNode(3);
	head->left->left = new TreeLinkNode(4);
	head->left->right = new TreeLinkNode(5);
	head->right->left = new TreeLinkNode(6);
	head->right->right = new TreeLinkNode(7);
	connect(head);


	return 0;
}