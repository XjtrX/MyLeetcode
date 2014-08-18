/*
autor: jtr@BNU
date:14.8.15
problem:
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int removeDuplicates(int A[], int n)
{
	if (n<2)
	{
		return n;
	}
	int cur = 0;

	for (int i = 1; i < n; ++i)
	{
		while(i < n && A[cur] == A[i])
		{
			i++;
		}
		if (i < n)
		{
			cur++;
			A[cur] = A[i];
		}
	}
	return cur+1;
}

int main(int argc, char const *argv[])
{
	int A[] = {1,2,3,3,4,4,4,4,5,6,7,7,7,7,8,9};
	int n = 16;
	for (int i = 0; i < n; ++i)
	{
		cout<<A[i]<<", ";
	}
	cout<<endl;

	cout<<removeDuplicates(A, n )<<endl;
	return 0;
}