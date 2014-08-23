/*
author: jtr@BNU
date: 14.8.23
problem:
Unique Paths Total Accepted: 17346 Total Submissions: 55359 My Submissions 





A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?




Above is a 3 x 7 grid. How many possible unique paths are there? 

Note: m and n will be at most 100.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



// int uniquePaths(int m, int n)
// {
// 	if (m < n)
// 	{
// 		int tem = m;
// 		m = n;
// 		n = tem;
// 	}
// 	if (n == 1)
// 	{
// 		return 1;
// 	}
// 	return uniquePaths(m - 1,n) + uniquePaths(m, n -1);
// }

//Divide and conquer
int C(int m, int n, vector<vector<int> > & Cmn)
{
	if (m < n)
	{
		int tem = m;
		m = n; n = tem;
	}
	if (n == 1)
	{
		Cmn[m][n] = 1;
		return 1;
	}
	if (Cmn[m][n])
	{
		return Cmn[m][n];
	}
	else
	{
		Cmn[m][n] = C(m - 1, n, Cmn) + C(m, n - 1, Cmn);
		return Cmn[m][n];
	}
}
int uniquePaths(int m, int n)
{
	if (m < n)
	{
		int tem = m;
		m = n; n = tem;
	}
	vector<vector<int> > Cmn(m+1,vector<int>(n+1,0));
	return C(m,n,Cmn);
}

int main(int argc, char const *argv[])
{
	int m = 23;
	int n = 12;

	cout<<m<<", "<<n<<endl<<uniquePaths(m,n)<<endl;
	return 0;
}