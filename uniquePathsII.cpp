/*
author: jtr@BNU
date: 14.8.23
peoblem:
Unique Paths II Total Accepted: 13238 Total Submissions: 47715 My Submissions 


Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,


There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]


The total number of unique paths is 2.

Note: m and n will be at most 100.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int times = 0;
void DFS(vector<vector<int> > &obstacleGrid, int &res, vector<pair<int,int> > &path)
{
	times++;
	if (path.back().first == obstacleGrid.size() - 1 && path.back().second == obstacleGrid.begin()->size() - 1)
	{
		res++;
		return;
	}
	else
	{
		int x = path.back().first;
		int y = path.back().second;
		if (x < obstacleGrid.size() - 1 && !obstacleGrid[x+1][y])
		{
			path.push_back(make_pair(x + 1, y));
			DFS(obstacleGrid, res, path);
			path.pop_back();
		}
		if (y < obstacleGrid.begin()->size() - 1 && !obstacleGrid[x][y + 1])
		{
			path.push_back(make_pair(x, y + 1));
			DFS(obstacleGrid, res, path);
			path.pop_back();
		}
	}
}

void DFS2(vector<vector<int> > &obstacleGrid, int &res, int x, int y)
{
	times++;
	if ( x == obstacleGrid.size() - 1 && y == obstacleGrid.begin()->size() - 1)
	{
		res++;
		return;
	}
	else
	{
		if (x < obstacleGrid.size() - 1 && !obstacleGrid[x+1][y])
		{
			x++;
			DFS2(obstacleGrid, res, x, y);
			x--;
		}
		if (y < obstacleGrid.begin()->size() - 1 && !obstacleGrid[x][y + 1])
		{
			y++;
			DFS2(obstacleGrid, res, x, y);
			y--;
		}
	}
}

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) 
{
	int m = obstacleGrid.size();
	int n = obstacleGrid.begin()->size();
	
	int res = 0;
	vector<pair<int, int> > path;
	if (!obstacleGrid[0][0])
	{
		// path.push_back(make_pair(0,0));
		// DFS(obstacleGrid, res, path);
		
		DFS2(obstacleGrid, res, 0 , 0);
		cout<<res<<endl;
		vector<int> P(n, 0);
		P[0] = obstacleGrid[0][0] ? 0 : 1;
		bool flag = false;
		for (int i = 0; i < m; ++i)
		{
			if(obstacleGrid[i][0]) flag = true;
			P[0] = (flag || obstacleGrid[i][0]) ? 0 : 1;
			for (int j = 1; j < n; ++j)
			{
				P[j] = obstacleGrid[i][j] ? 0 : P[j] + P[j-1];
			}
		}
		return P[n-1];
	}
	return res;
}


int main(int argc, char const *argv[])
{
	vector<vector<int> > obstacleGrid = {
		{0,1,0,0,0,1},
		{0,1,0,0,0,0},
		{0,0,0,0,0,0},
		{1,1,0,1,0,0},
		{0,0,0,0,0,0}
	};
	for (std::vector<vector<int> >::iterator itr = obstacleGrid.begin(); itr != obstacleGrid.end(); ++itr)
	{
		for (std::vector<int>::iterator i = (*itr).begin(); i != (*itr).end(); ++i)
		{
			cout<<*i;
		}
		cout<<endl;
	}

	cout<<uniquePathsWithObstacles(obstacleGrid)<<endl;
	cout<<times<<endl;
	return 0;
}

