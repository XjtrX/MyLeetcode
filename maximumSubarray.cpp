/*
author: jtr@BNU
date:14.8.22
problem:
Maximum Subarray Total Accepted: 22393 Total Submissions: 66596 My Submissions
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;


int maxSubArray(int A[], int n)
{
	int res = A[0];
	if (n == 1)
	{
		return A[0];
	}

	int cur = 0;
	while(A[cur] < 0) 
	{
		res = max(res, A[cur]);
		cur++;
	}
	int tem = 0;
	int po = cur;
	while(po < n)
	{
		if (tem + A[po] < 0)
		{
			
			tem = 0;
		}
		else
			tem += A[po];
		res = max(res,tem);
		++po;
	}
	if (po>cur)
	{
		res = max(res,tem);
	}
	
	return res;
}

int main(int argc, char const *argv[])
{
	int A[] = {-2,1,-3,4,-1,2,1,-5,4};
	int n = 9;

	for (int i = 0; i < n; ++i)
	{
		cout<<A[i]<<", ";
	}
	cout<<endl<<endl;
	cout<<maxSubArray(A,n)<<endl;
	return 0;
}