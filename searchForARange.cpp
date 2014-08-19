/*
author: jtr@BNU
date: 14.8.19
problem:
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> searchRange(int A[], int n, int target)
{
	vector<int> res(2,-1);
	if (n<1)
	{
		return res;
	}
	int left = 0, right = n - 1;
	int mid_left, mid_right, mid;
	while(left <= right)
	{
		mid = (left+right)/2;

		if (A[mid] == target)
		{
			int tem;
			mid_right = mid_left = mid;
			//left
			while(left <= mid_left)
			{
				tem = (left + mid_left)/2;
				if (A[tem] < target)
				{
					left = tem + 1;
				}
				else
					mid_left = tem;
				if (left == mid_left)
				{
					res[0] = mid_left;
					break;
				}
			}
			//right
			while(mid_right <= right)
			{
				tem = (right + mid_right + 1) / 2;
				if (A[tem] > target)
				{
					right = tem - 1;
				}
				else
				mid_right = tem ;
				if (right == mid_right)
				{
					res[1] = mid_right;
					return res;
				}
			}
		}
		else if (A[mid] < target)
		{
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int A[] = {1};
	int n = 1;
	int target = 1;

	for (int i = 0; i < n; ++i)
	{
		cout<<A[i]<<", ";
	}
	cout<<endl;
	cout<<target<<endl;
	std::vector<int> res = searchRange(A, n , target);

	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<", ";
	}
	cout<<endl;
	return 0;
}