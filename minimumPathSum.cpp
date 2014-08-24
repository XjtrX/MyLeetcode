/*
author: jtr@BNU
date: 14.8.24
problem:
Minimum Path Sum Total Accepted: 15381 Total Submissions: 49409 My Submissions
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int> > & grid)
{
	int m = grid.size();
	int n = grid.begin()->size();

	vector<int> P(n, 0);

	P[0] = grid[0][0];

	for (int i = 0; i < m; ++i)
	{
		P[0] = (i==0)?grid[0][0] : grid[i][0] + P[0];

		for (int j = 1; j < n; ++j)
		{
			P[j] = (i==0) ? grid[i][j] + P[j - 1] : min(P[j-1], P[j]) + grid[i][j];
		}
	}
	return P[n-1];
}

int main(int argc, char const *argv[])
{
	vector<vector<int> > grid = {
		{1,2,3,4},
		{1,2,3,4},
		{1,1,1,1},
		{1,2,0,4}
	};
	for (std::vector<std::vector<int> >::iterator itr = grid.begin(); itr != grid.end(); ++itr)
	{
		for (std::vector<int>::iterator i = (*itr).begin(); i != (*itr).end(); ++i)
		{
			cout<<*i<<", ";
		}
		cout<<endl;
	}
	cout<<minPathSum(grid)<<endl;
	return 0;
}