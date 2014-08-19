/*
author: jtr@BNU
date:14.8.19
problem:
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
#include <iostream>
using namespace std;


int searchInsert(int A[], int n, int target)
{
	int res = 0;
	if (n < 1)
	{
		return 0;
	}
	int left = 0, right = n - 1;
	int mid;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if (A[mid] == target)
		{
			return mid;
		}
		if (A[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = right - 1;
		}
	}
	return left;
}

int main(int argc, char const *argv[])
{
	int A[] = {1,2,3,4,5,6,7,8,9,16};
	int n = 1;
	int target = 0;
	for (int i = 0; i < n; ++i)
	{
		cout<<A[i]<<", ";
	}
	cout<<endl;

	cout<<target<<"-> "<<searchInsert(A, n, target)<<endl;
	return 0;
}