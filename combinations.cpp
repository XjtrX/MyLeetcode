/*
author: jtr@BNU
date: 14.8.31
problem:
Combinations Total Accepted: 18319 Total Submissions: 60453 My Submissions
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int> > &res, vector<int> & path, int cur, int n, int k)
{
	if (path.size() == k)
	{
		res.push_back(path);
		return;
	}
	for (int i = cur; i < n + 1; ++i)
	{
		// cout<<n<<", "<<k<<", "<<i<<endl;
		path.push_back(i);
		dfs(res, path, i + 1, n , k);
		path.pop_back();
	}
}
vector<vector<int> > combine(int n, int k)
{
	vector<vector<int> > res;
	std::vector<int> path;
	dfs(res, path, 1, n, k);
	return res;
}

int main(int argc, char const *argv[])
{
	int n = 5;
	int k = 3;
	cout<<n<<endl<<k<<endl;

	cout<<endl;

	std::vector<std::vector<int> > res = combine(n,k);
	for (std::vector<vector<int> >::iterator itr = res.begin(); itr != res.end(); ++itr)
	{
		for (std::vector<int >::iterator i = itr->begin(); i != itr->end(); ++i)
		{
			cout<<*i<<", ";
		}
		cout<<endl;
	}
	return 0;
}