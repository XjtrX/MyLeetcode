/*
author: jtr@BNU
date:14.8.22
problem:
Jump Game II Total Accepted: 14777 Total Submissions: 60214 My Submissions
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

// //TLE
// int jump(int A[], int n)
// {
	
// 	if(*A >= n - 1)
// 		return 1;
// 	else
// 	{
		
// 		int i = 1;
// 		int res = 0x7fffffff;
// 		while(i <= *A)
// 		{
			
// 			res = min(res,1 + jump(A + i, n - i));
// 			i++;
// 		}

// 		return res;
// 	}
// }
//TLE also
// int nextStep(vector<int> & steps,int A[], int start, int n)
// {
// 	if (A[start] >= (n - 1 - start))
// 	{
// 		steps[start] = 1;
// 		return 1;
// 	}
// 	if (steps[start] != 0)
// 	{
// 		return steps[start];
// 	}
// 	int i = 1;
// 	int res = 0x7fffffff;
// 	while(i <= A[start])
// 	{
// 		res = min(res, 1 + nextStep(steps,A, start + i,n));
// 		i++;
// 	}
// 	steps[start] = res;
// 	return res;
// }


// int jump(int A[], int n)
// {
// 	vector<int> steps(n,0);
// 	return nextStep(steps,A,0,n);
// }

int jump(int A[], int n)
{
	if (0 == n - 1)
	{
		return 0;
	}
	int res = 1;
	for (int i = 0; i < n; )
	{
		if (A[i] == 0 && i != n - 1)
		{
			return 0x7fffffff;
		}
		int tem = 0, next;
		int cur = 1;
		while(cur <= A[i])
		{
			if(cur+i >= n - 1) return res;
			if (A[i + cur] + i + cur > tem)
			{
				next = i + cur;
				tem = A[i + cur] + i + cur;
			}
			cur++;
		}
		res++;
		i = next;
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int A[] = {10,9,8,7,6,5,4,3,2,1,1,0};
	int n = 12;
	for (int i = 0; i < n; ++i)
	{
		cout<<A[i]<<", ";
	}
	cout<<endl;

	cout<<jump(A, n)<<endl;
	return 0;
}