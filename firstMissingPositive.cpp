/*
author: jtr@BNU
date: 14.8.21
problem:
First Missing Positive Total Accepted: 14898 Total Submissions: 66405 My Submissions
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;


int firstMissingPositive(int A[], int n)
{
	int res = 1;

	if (n<1 || (n == 1 && A[0] != 1))
	{
		return 1;
	}
	int tem;
	int t = 0;
	for (int i = 0; i < n; ++i)
	{
		res = A[i];
		while(res > 0 && res < n + 1 && res != A[res - 1])
		{
			tem = A[res - 1];
			A[res - 1] = res;
			res = tem;
			t++;
		}
		if (t >= n)
		{
			break;
		}
	}
	res = 1;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] != res)
		{
			return res;
		}
		res++;
	}
	return res;
}


int main(int argc, char const *argv[])
{
	int A[] = {3,4,6,-1,2,1};
	int n = 6;

	for (int i = 0; i < n; ++i)
	{
		cout<<A[i]<<",";
	}

	cout<<endl;

	cout<<firstMissingPositive(A, n)<<endl;
	return 0;
}