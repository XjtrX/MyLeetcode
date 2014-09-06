/*
author: jtr@BNU
date: 14.9.5
problem:
Sum Root to Leaf Numbers Total Accepted: 20249 Total Submissions: 68025 My Submissions
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

#include "myIncs.h"


int sumNumbers(TreeNode * root)
{
	int res = 0;
	string str = "";
	if(root == NULL) return res;
	if(root->left == NULL && root->right == NULL) return root->val;
	stack<TreeNode *> S;
	map<TreeNode *, int> visited;
	S.push(root);
	visited[root]++;
	str.push_back(root->val + '0');
	while(!S.empty())
	{
		while(S.top()->left && visited[S.top()->left] == 0)
		{
			S.push(S.top()->left);
			visited[S.top()]++;
			str.push_back(S.top()->val + '0');
		}
		// cout<<str<<endl;
		if(S.top()->right == NULL && S.top()->left == NULL && visited[S.top()] == 1)
		{
			res += atoi(str.c_str());
			str.pop_back();	
			S.pop();
		}
		else if(S.top()->right && visited[S.top()] < 2)
		{
			visited[S.top()]++;
			S.push(S.top()->right);
			str.push_back(S.top()->val + '0');
			visited[S.top()]++;
		}
		else
		{
			S.pop();
			str.pop_back();
		}
	}
	return res;
}


int main(int argc, char const *argv[])
{
	TreeNode * root = new TreeNode(1);
	// root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	// root->left->right = new TreeNode(4);
	// root->left->left = new TreeNode(0);


	cout<<sumNumbers(root)<<endl;
	return 0;
}