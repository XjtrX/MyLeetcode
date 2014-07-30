#ifndef MAXPATHSUM_H
#define MAXPATHSUM_H

#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <map>


/*
JTR@BNU 
*/
/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
namespace maxPathSum{
	using namespace std;
struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution
{
public:
	map<TreeNode*, bool> flag;
	map<TreeNode*,  int> sumTree;
	int maxPathSum(TreeNode * root){
		if (root == NULL)
		{
			return 0;
		}
		if (root->left == NULL && root->right == NULL)
		{
			return root->val;
		}
		//We can find the farthest point from the root
		//map<TreeNode * , int>
		int res = -99999999;
		TreeNode * cur = root;
		queue<TreeNode * > levelSeache;
		levelSeache.push(cur);
		while(!levelSeache.empty()){
			TreeNode * tem = levelSeache.front();
			levelSeache.pop();
			if (tem->left != NULL)
			{
				levelSeache.push(tem->left);
			}
			if (tem -> right != NULL)
			{
				levelSeache.push(tem->right);
			}
			int sumL = farthestPoint(tem->left);
			int sumR = farthestPoint(tem->right);
			int sumMax = 0;
			sumMax += sumL>0? sumL : 0;
			sumMax += sumR>0? sumR : 0;
			sumMax += tem->val;
			if (res < sumMax)
			{
				res = sumMax;
			}
		}
		return res;

	}

	int farthestPoint(TreeNode * root){
		int res = 0;
		if(root == NULL) return res;
		if (flag[root])
		{
			return sumTree[root];
		}
		if(root->left == NULL && root->right == NULL) 
		{
			res = root->val;
			flag[root] = true;
			sumTree[root] = res;
			return res;
		}
		int sumLeft = farthestPoint(root->left) ;
		int sumRight = farthestPoint(root->right) ;
		sumLeft =  sumLeft>=0 ? sumLeft + root->val : root->val;
		sumRight  = sumRight >= 0 ? sumRight + root->val : root->val;
		res += ((sumLeft>sumRight) ? sumLeft : sumRight);
		flag[root] = true;
		sumTree[root] = res;
		return res;
	}
	void test()
	{
		TreeNode * root = new TreeNode(100);
		TreeNode * cur  = root;
		cur->left = new TreeNode(42);
		cur->right  = new TreeNode(-11);
		cur = cur->left;
		cur->right  = new TreeNode(-11);
		cur->left = new TreeNode(22);



		cout<<maxPathSum(root)<<endl;
	}
};

}

#endif