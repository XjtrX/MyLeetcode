/*
author: jtr@BNU
date: 14.8.21
problem:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

int trap(int A[], int n)
{
	int res = 0;
	if (n < 3)
	{
		return 0;
	}
	int leftmax = 0, rightmax = 0;
	int prelow = 0, backlow = n -1;
	int left = prelow + 1 , right = backlow - 1;
	int leftsum = 0, rightsum = 0;

	// int maxleft = A[0], maxright = A[n - 1];
	while(left <= n - 1)
	{
		int tem = 0;
		while(left <= n - 1 && A[left] < A[prelow])
		{
			tem -= A[left];
			left++;
		}
		if (n - 1 >= left && A[left] >= A[prelow])
		{
			leftsum += (left - prelow - 1) * (A[prelow]);
			leftsum += tem;
			// cout<<"left : "<<left<<" - "<<prelow<<", tem= "<<tem<<", leftsum = "<<leftsum<<endl;
			prelow = left;
			// maxleft = max(maxleft, A[prelow]);
			left++;
		}
	}

	left = 0;
	while(prelow <= right)
	{
		int tem = 0;
		while(prelow <= right && A[right] < A[backlow])
		{
			tem -= A[right];
			right--;
		}
		if ( right >= prelow && A[right] >= A[backlow])
		{
			rightsum += (backlow - right - 1) * (A[backlow]);
			rightsum += tem;
			// cout<<"right: "<<backlow<<" - "<<right<<", tem= "<<tem<<", rightsum = "<<rightsum<<endl;
			backlow = right;
			// maxright = max(maxright, A[backlow]);
			right--;
		}
	}

	res = leftsum + rightsum;
	return res;
}

int main(int argc, char const *argv[])
{
	int A[] = {5,5,1,5,1,1,5,2,5,5};
	int n = 10;
	for (int i = 0; i < n; ++i)
	{
		cout<<A[i]<<", ";
	}
	cout<<endl;

	cout<<trap(A, n)<<endl;
	return 0;
}