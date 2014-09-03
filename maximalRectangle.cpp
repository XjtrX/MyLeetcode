/*
author: jtr@BNU
date: 14.9.2
problem:
Maximal Rectangle Total Accepted: 10593 Total Submissions: 49016 My Submissions
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/


#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


int maximalRectangle(vector<vector<char> > & matrix)
{
	int res = 0;
	
	int row = matrix.size();
	if (row == 0) return 0;
	int len = matrix.begin()->size();
	if (row == 0 || len == 0) return 0;

	vector<vector<int> > M(row, vector<int>(len));
	for (int i = 0; i < row; ++i)
	{
		M[i][0] = matrix[i][0] - '0';
		for (int j = 1; j < len; ++j)
		{
			if (matrix[i][j] == '1')
			{
				M[i][j] = M[i][j-1] + 1;
			}
		}
	}
	// cout<<"size: "<<M.size()<<", "<<M[0].size()<<endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			int minlen = M[i][j];
			for (int k = i; k < row ; ++k)
			{
				if (M[k][j] == 0) break;
				// cout<<i<<", "<<j<<", "<<k<<endl;
				minlen = min(minlen, M[k][j]);
				res = max(res, minlen * (k - i + 1));
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<vector<char> > matrix = {
		{'1','1','0','0','0','0','0','0',},
		{'1','1','0','1','1','1','1','1',},
		{'1','1','1','1','1','1','0','0',},
		{'1','1','1','1','1','1','0','0',},
		{'1','1','0','0','1','1','0','0',},
		{'1','0','0','0','0','0','0','0',}
	};

	for (std::vector<vector<char> >::iterator itr = matrix.begin(); itr != matrix.end(); ++itr)
	{
		for (std::vector<char>::iterator i = itr->begin(); i != itr->end(); ++i)
		{
			cout<<*i;
		}
		cout<<endl;
	}

	cout<<maximalRectangle(matrix)<<endl;
	return 0;
}