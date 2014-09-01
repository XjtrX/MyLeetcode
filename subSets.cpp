/*
author: jtr@BNU
date: 14.9.1
problem:
Subsets Total Accepted: 20336 Total Submissions: 72907 My Submissions
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int> > &res, std::vector<int> & path,vector<int>::iterator cur, vector<int> & S)
{
	if (path.size() <= S.size())
	{
		res.push_back(path);
	}
	for (std::vector<int>::iterator i = cur; i != S.end(); ++i)
	{
		path.push_back(*i);
		DFS(res, path, i + 1, S);
		path.pop_back();
	}
}
vector<vector<int> > subsets(vector<int> & S)
{
	sort(S.begin(), S.end());

	vector<vector<int> > res;
	vector<int> path;

	DFS(res,path,S.begin(), S);
	return res;
}

int main(int argc, char const *argv[])
{
	std::vector<int > S = {1,2,3,4};

	std::vector<std::vector<int> > res = subsets(S);
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