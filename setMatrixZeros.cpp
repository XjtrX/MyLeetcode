/*
author: jtr@BNU
date: 14.8.30
problem:
Set Matrix Zeroes Total Accepted: 15757 Total Submissions: 51083 My Submissions
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

void setZeroes(vector<vector<int> > & matrix)
{
	int row = matrix.size();
	int len = matrix.begin()->size();

	set<int> rows, lens;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			if (matrix[i][j] == 0)
			{
				rows.insert(i);
				lens.insert(j);
			}
		}
	}

	for(set<int>::iterator itr = rows.begin(); itr != rows.end(); ++itr)
	{
		for (int i = 0; i < len; ++i)
		{
			matrix[*itr][i] = 0;
		}
	}
	for (std::set<int>::iterator itr = lens.begin(); itr != lens.end(); ++itr)
	{
		for (int i = 0; i < row; ++i)
		{
			matrix[i][*itr] = 0;
		}
	}
}


int main(int argc, char const *argv[])
{
	vector<vector<int> > matrix = {
		{1,2,3,4,1,0},
		{2,3,4,1,0,1},
		{3,0,2,1,1,3}
	};

	for (std::vector<vector<int> >::iterator itr = matrix.begin(); itr != matrix.end(); ++itr)
	{
		for (std::vector<int>::iterator i = itr->begin(); i != itr->end(); ++i)
		{
			cout<<*i<<", ";
		}
		cout<<endl;
	}
	cout<<"---------------"<<endl;
	setZeroes(matrix);
	for (std::vector<vector<int> >::iterator itr = matrix.begin(); itr != matrix.end(); ++itr)
	{
		for (std::vector<int>::iterator i = itr->begin(); i != itr->end(); ++i)
		{
			cout<<*i<<", ";
		}
		cout<<endl;
	}
	return 0;
}