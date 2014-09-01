/*
author: jtr@BNU
date: 14.9.1
problem:
Search in Rotated Sorted Array II Total Accepted: 15135 Total Submissions: 49318 My Submissions
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

bool search(int A[], int n, int target)
{
	if (n < 1)
	{
		return false;
	}
	bool res = false;

	if (target == A[0]) return true;

	int min = 0;
	while(A[min] == A[0])min++;
	int max = n - 1;
	while(A[max] == A[0])max--;

	int left = min, right = max;
	int mid = (left + right)/ 2;
	bool flag = true;//left
	if (target < A[min])
	{
		flag = false; //right
	}

	while(left <= right)
	{
		if (left == right)
		{
			return target == A[left];
		}
		mid = (left + right)/ 2;
		if (A[mid] == target)
		{
			return true;
		}
		if (flag )//left
		{
			if (A[mid] >= A[min])//left
			{
				if (A[mid] < target)//
				{
					left = mid + 1;
				}
				else
					right = mid - 1;
			}
			else if (A[mid] < A[min])
			{
				right = mid - 1;
			}
		}else
		{
			if (A[mid] >= A[min])
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
	int A[] = {1,1,1,1,1,1,3,1,1,1};
	int n = 10;
	int target = 3;

	for (int i = 0; i < n; ++i)
	{
		cout<<A[i]<<", ";
	}
	cout<<endl;

	cout<<n<<endl<<target<<endl;
	cout<<(search(A,n,target)?"exit.":"No exit.")<<endl;
	return 0;
}