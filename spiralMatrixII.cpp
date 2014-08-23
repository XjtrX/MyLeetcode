/*
author: jtr@BNU
date: 14.8.23
problem:
Spiral Matrix II Total Accepted: 12261 Total Submissions: 39911 My Submissions
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int> > generateMatrix(int n)
{
	// vector<vector<int> >  res(n,vector<int>(n));
	vector<vector<int> > res;
	if (n<1) //if dont add this it will be runtime error.
	{
		return res;
	}
	for (int i = 0; i < n; ++i)
	{
		vector<int> tem;
		for (int j = 0; j < n; ++j)
		{
			tem.push_back(0);
		}
		res.push_back(tem);
	}
	int left = 0, right = n -1, up = 0, down = n - 1; 
	int state = 0;//direction: 0:right, 1:down, 2: left, 3: up
	int total = n * n, cur = 1;
	int x = 0, y = 0; //start position
	do{
		switch(state)
		{
			case 0:
				res[x][y] = cur;
				if (y == right)
				{
					state = 1;
					up++;
					x++;
				}
				else
				{
					y++;
				}
				break;
			case 1:
				res[x][y] = cur;
				if (x == down)
				{
					state = 2;
					right--;
					y--;
				}
				else
					x++;
				break;
			case 2:
				res[x][y] = cur;
				if (y == left)
				{
					state = 3;
					down--;
					x--;
				}
				else{
					y--;
				}
				break;
			case 3:
				res[x][y] = cur;
				if (x == up)
				{
					state = 0;
					left++;
					y++;
				}
				else
					x--;
				break;
			default:
				break;
		}
	}while(++cur <= total);

	return res;
}

int main(int argc, char const *argv[])
{
	int n = 0;

	cout<<n<<endl;
	vector<vector<int> > res = generateMatrix(n);
	for (std::vector<vector<int> >::iterator itr = res.begin(); itr != res.end(); ++itr)
	{
		for (std::vector<int >::iterator i = (*itr).begin(); i != (*itr).end(); ++i)
		{
			cout<<*i<<", ";
		}
		cout<<endl;
	}
	return 0;
}