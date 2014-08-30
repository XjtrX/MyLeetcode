/*
author: jtr@BNU
date: 14.8.30
problem:
Sort Colors Total Accepted: 21310 Total Submissions: 66570 My Submissions
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

void sortColors(int A[], int n)
{
	int left = 0, right = 0;
	int red = 0, white = 0, blue = 0;
	for(int i = 0; i < n - right; ++i)
	{
		switch(A[i])
		{
			case 0:
				A[left] = 0;
				left++;
				break;
			case 1:
				white++;
				break;
			case 2:
				while( n - 1 - right > i && A[n - 1 - right] == 2) right++;
				if ( A[n - 1 - right] == 1)
				{
					white++;
				}
				else if(A[n - right - 1] == 0)
				{
					A[left] = 0;
					left++;
				}
				A[n - 1 - right] = 2;
				break;
			default:
				break;
		}
	}
	for (int i = 0; i < white; ++i)
	{
		A[left + i] = 1;
	}
}


int main(int argc, char const *argv[])
{
	int A[] = {1,2};
	int n = 2;

	for(int i = 0; i< n ; ++i)
		cout<<A[i]<<", ";
	cout<<endl;
	cout<<n<<endl;
	sortColors(A,n);
	for(int i = 0; i< n ; ++i)
		cout<<A[i]<<", ";
	cout<<endl;
	return 0;
}