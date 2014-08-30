/*
author: jtr@BNU
date: 14.8.30
problem:
Search a 2D Matrix Total Accepted: 17986 Total Submissions: 57672 My Submissions
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>

using namespace std;

bool searchMatrix(vector<vector<int> > & matrix, int target)
{
	int row = matrix.size(), len = matrix.begin()->size();
	int high = 0, low = row - 1;
	int mid = (high + low)/2;
	if (row == 0 || len == 0)
	{
		return false;
	}
	while(high <= low)
	{
		// cout<<"low , high = "<<low<<", "<<high<<endl;
		mid = (high + low)/2;
		if (target == matrix[mid][len - 1])
		{
			return true;
		}
		if (target < matrix[mid][len - 1])
		{
			low = mid - 1;
		}
		else if (target > matrix[mid][len - 1])
		{
			high = mid + 1;
		}
	}
	// cout<<"-----"<<endl;
	high = ((high >= row) ? 0 : high);
	// cout<<"high = "<<high<<endl;
	int left = 0, right = len - 1;
	while(left <= right)
	{
		// cout<<"left, right = "<<left<<", "<<right<<endl;
		mid = (left + right)/2;
		if (target == matrix[high][mid])
		{
			return true;
		}
		else if (target < matrix[high][mid])
		{
			right = mid - 1;
		}
		else if (target > matrix[high][mid])
		{
			left = mid + 1;
		}
	}

	return false;
}

int main(int argc, char const *argv[])
{
	std::vector<vector<int> > matrix = {
	{1}
	};


	for (std::vector<vector<int> >::iterator itr = matrix.begin(); itr != matrix.end(); ++itr)
	{
		for (std::vector<int>::iterator i = itr->begin(); i != itr->end(); ++i)
		{
			cout<<*i<<", ";
		}
		cout<<endl;
	}
	int target = 2;

	cout<<target<<endl;
	bool res = searchMatrix(matrix, target);
	cout<<(res ? "Yes." : "No.")<<endl;
	return 0;
}