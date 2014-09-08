/*
author: jtr@BNU
date: 14.9.8
problem:
Single Number II Total Accepted: 24835 Total Submissions: 73342 My Submissions
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/


#include "myIncs.h"

int singleNumber(int A[], int n)
{
	vector<char> res(sizeof(int) * 8, 0);
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < sizeof(int) * 8; ++k)
		{
			if(A[i] & (1<<k)) res[k] = (res[k] + 1)%3;
		}
	}
	int tem = 0;
	for (int i = 0; i < sizeof(int) * 8; ++i)
	{
		tem += (res[i]<<i);
	}
	return tem;
}


int main(int argc, char const *argv[])
{
	int A[] = {1,1,1,2,2,2,5};

	int n = 1;

	for (int i = 0; i < n; ++i)
	{
		cout<<A[i]<<", ";
	}
	cout<<endl<<n<<endl;

	cout<<singleNumber(A, n)<<endl;

	return 0;
}