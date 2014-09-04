/*
author: jtr@BNU
date: 14.9.4
problem:
Populating Next Right Pointers in Each Node II Total Accepted: 16684 Total Submissions: 54949 My Submissions 





Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note: 
•You may only use constant extra space.


For example,
 Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7



After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL


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
		if(cur == NULL)
		{
			Q.push(NULL);
			cur = Q.front();
			Q.pop();
		}
		if(Q.empty()) return;
		if(cur->left)
		{
			Q.push(cur->left);
		}
		if(cur->right) 
		{
			Q.push(cur->right);
		}
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
	//head->right->left = new TreeLinkNode(6);
	head->right->right = new TreeLinkNode(7);
	connect(head);


	return 0;
}