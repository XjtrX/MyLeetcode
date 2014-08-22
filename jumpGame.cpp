/*
author: jtr@BNU
date: 14.8.22
peoblem:
Jump Game Total Accepted: 17263 Total Submissions: 63559 My Submissions
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool canJump(int A[], int n)
{
	if (n == 1)
	{
		return true;
	}
	bool can = true;
	int tem = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		tem = max(tem, i + A[i]);
		if (A[i] == 0 && tem <= i)
		{
			return false;
		}
	}
	return can;
}

int main(int argc, char const *argv[])
{
	int A[] = {1,2,3,4,1,0,0,4,0,2};
	int n = 10;
	for (int i = 0; i < n; ++i)
	{
		cout<<A[i]<<", ";
	}
	cout<<endl;

	cout<< ((canJump(A,n)) ? "Can jump." : "Cant jump.")<<endl;
	return 0;
}