/*
author: jtr@BNU
date: 14.9.1
problem:
Remove Duplicates from Sorted Array II Total Accepted: 17792 Total Submissions: 58141 My Submissions
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int removeDuplicates(int A[], int n)
{
	
	if (n < 3)
	{
		return n;
	}
	int res = 1;
	int cur = A[0];
	int curt = 1;
	for (int i = 1; i < n; ++i)
	{
		if (cur == A[i] && curt < 2)
		{
			A[res] = A[i];
			curt++;
			res++;
		}
		else if (cur == A[i] && curt == 2)
		{
			while(i < n && cur == A[i]) ++i;
			if (i == n) return res;
			--i;
		}
		else if (cur != A[i])
		{
			A[res++] = A[i];
			cur = A[i];
			curt = 1;
		}
	}
	return res ;
}

int main(int argc, char const *argv[])
{
	int A[] = {1,1,1,1,1};
	int n = 3;
	for (int i = 0; i < n; ++i)
	{
		cout<<A[i]<<", ";
	}
	cout<<endl;

	int res = removeDuplicates(A, n);
	cout<<n<<endl<<endl<<res<<endl;

	for(int i = 0; i < res; i++)
		cout<<A[i]<<", ";
	cout<<endl;
	return 0;
}