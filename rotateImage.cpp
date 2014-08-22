/*
author: jtr@BNU
date: 14.8.22
problem:
Rotate Image Total Accepted: 15037 Total Submissions: 47842 My Submissions
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int> > & matrix)
{
	int n = matrix.size();//width = height
	for (int i = 0; i < (n+1)/2; ++i) //# of circle, out -> in
	{
		//cout<<i<<" circle..."<<endl;
		int start = i, end = n - i - 1;
		for (int j = 0 ; j < n - 2*i - 1; ++j)
		{
			int x1,x2,x3,x4,y1,y2,y3,y4;
			x1 = start;
			x2 = start + j;
			y1 = start + j;
			y4 = start;
			x3 = end;
			x4 = end - j;
			y2 = end;
			y3 = end - j;
			// cout<<"x1-4,y1-4: ("<<x1<<","<<y1<<"),("<<x2<<","<<y2<<"),("<<x3<<","<<y3<<"),("<<x4<<","<<y4<<")"<<endl;
			int tem = matrix[x1][y1];
			matrix[x1][y1] = matrix[x4][y4];
			matrix[x4][y4] = matrix[x3][y3];
			matrix[x3][y3] = matrix[x2][y2];
			matrix[x2][y2] = tem;
		}
	}
}

int main(int argc, char const *argv[])
{
	vector<vector<int> > matrix ={
		{1,2,3,4},
		{1,2,3,4},
		{1,2,3,4},
		{1,2,3,4}
		// {1,2,3,4,5,6},
		// {1,2,3,4,5,6}
		// {1,2,3,4,5,6,7,8,9,0},
		// {1,2,3,4,5,6,7,8,9,0},
		// {1,2,3,4,5,6,7,8,9,0},
		// {1,2,3,4,5,6,7,8,9,0}
	};

	for (std::vector<std::vector<int> >::iterator itr = matrix.begin(); itr != matrix.end(); ++itr)
	{
		for (std::vector<int>::iterator i = (*itr).begin(); i != (*itr).end(); ++i)
		{
			cout<<*i<<" ";
		}
		cout<<endl;
	}

	rotate(matrix);
	cout<<"After rotate:"<<endl;
	for (std::vector<std::vector<int> >::iterator itr = matrix.begin(); itr != matrix.end(); ++itr)
	{
		for (std::vector<int>::iterator i = (*itr).begin(); i != (*itr).end(); ++i)
		{
			cout<<*i<<" ";
		}
		cout<<endl;
	}

	return 0;
}