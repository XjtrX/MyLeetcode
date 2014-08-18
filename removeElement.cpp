/*
author: jtr@BNU
date: 14.8.18
problem:
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

int removeElement(int A[], int n, int elem)
{
	int res = 0;

	if (n<1)
	{
		return 0;
	}

	int left = 0, right = n - 1;
	for (int i = 0; i <= right; ++i)
	{
		if (A[i] == elem)
		{
			while(right > i && A[right] == elem) {
				right--;
				res++;
			}
			if (right>=i)
			{
				res++;
				A[i] = A[right];
				right--;
			}
		}
	}
	return n - res;
}

int main(int argc, char const *argv[])
{
	int A[] = {1,3,21,32,21,1,4,142,14,21,32,14,21};
	int n = 13;
	int elem = 21;
	for (int i = 0; i < n; ++i)
	{
		cout<<A[i]<<", ";
	}
	cout<<endl<<n<<endl<<elem<<endl;


	cout<<removeElement(A, n, elem)<<endl;
	return 0;
}