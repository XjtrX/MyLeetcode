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

	/*
	Path Sum II:
	Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

	*/
//root to leaf
    	vector<vector<int> > pathSum(TreeNode *root, int sum) {
    		std::vector<vector<int>  > res;
    		res.clear();
    		if (root == NULL)
    		{
    			return res;
    		}

    		vector<int > path;
    		path.clear();
    		//path.psuh_back(root->val);
    		checkSum(root, sum, path, res);
    		return res;
    	}

    	void checkSum(TreeNode * root, int sum, vector<int> & path, vector<vector<int> > &res)
    	{
    		if (root == NULL)
    		{
    			//path.pop_back();
    			return ;
    		}
    		if (root-> left == NULL && root->right == NULL && sum == root->val)
    		{
    			path.push_back(root->val);
    			res.push_back(path);
    			path.pop_back();
    			return ;
    		}
    		path.push_back(root->val);
    		checkSum(root->left, sum - root->val, path, res);
    		checkSum(root->right, sum - root->val, path, res);
    		path.pop_back();
    	}
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
		cur = root->right;
		cur->left = new TreeNode(42);
		cur->right = new TreeNode(43);
		cur = cur->right;
		cur->left = new TreeNode(-1);


		cout<<maxPathSum(root)<<endl;

		cout<<"-----------------------"<<endl;
		vector< vector<int> > res;
		res = pathSum(root, 131);
		for(vector<vector<int> >::iterator itr = res.begin(); itr != res.end(); ++itr){
			for (vector<int>::iterator i = itr->begin(); i !=  itr->end(); ++i)
			{
				cout<<*i<<",";
			}
			cout<<endl;
		}

	}
};

}

#endif