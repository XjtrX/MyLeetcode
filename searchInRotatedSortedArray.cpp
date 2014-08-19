/*
author: jtr@BNU
date: 14.8.19
problem:
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int search(int A[], int n, int target)
{
	int res = -1;
	if (n < 1)
	{
		return -1;
	}
	bool flag = true;//left
	if (target < A[0])
	{
		flag = false; //right
	}
	int left = 0, right = n -1;
	int mid = (left + right) / 2;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if (A[mid] == target)
		{
			return mid;
		}
		if (flag)//left
		{
			if (A[mid] >= A[0])//left
			{
				if (A[mid] < target)//
				{
					left = mid + 1;
				}
				else
					right = mid - 1;
			}
			else if (A[mid] < A[0])
			{
				right = mid - 1;
			}
		}else
		{
			if (A[mid] >= A[0])
			{
				left = mid + 1;
			}
			else
			{
				if (A[mid] > target)
				{
					right = mid - 1;
				}
				else
					left = mid + 1;
			}

		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int A[] = {7,8,9,0,1,2,3,4,5,6};
	int n = 10;
	int target = 6;
	for (int i = 0; i < n; ++i)
	{
		cout<< A[i]<<", ";
	}
	cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<i+1<<"-->"<<search(A, n , i + 1)<<endl;
	}
	
	return 0;
}