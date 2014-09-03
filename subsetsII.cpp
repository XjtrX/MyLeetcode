/*
author: jtr@BNU
date: 14.9.3
peoblem:
Subsets II Total Accepted: 15916 Total Submissions: 59016 My Submissions
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

#include "myIncs.h"

void DFS(vector<vector<int> > &res, std::vector<int> & path,vector<int>::iterator cur, vector<int> & S)
{
	if (path.size() <= S.size() && find(res.begin(), res.end(), path) == res.end())
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

vector<vector<int> > subsetsWithDup(vector<int> & S)
{
	sort(S.begin(), S.end());

	vector<vector<int> > res;
	vector<int> path;

	DFS(res,path,S.begin(), S);
	return res;
}

int main(int argc, char const *argv[])
{
	std::vector<int> S = {1,2,2,3};

	for (std::vector<int>::iterator i = S.begin(); i != S.end(); ++i)
	{
		cout<<*i<<", ";
	}
	cout<<endl;

	vector<vector<int> > res  = subsetsWithDup(S);
	for (std::vector<vector<int> >::iterator itr = res.begin(); itr != res.end(); ++itr)
	{
		for (std::vector<int>::iterator i = itr->begin(); i != itr->end(); ++i)
		{
			cout<<*i<<",";
		}
		cout<<endl;
	}
	return 0;
}