/*
author: jtr@BNU
date: 14.9.3
problem:
Merge Sorted Array Total Accepted: 21551 Total Submissions: 67120 My Submissions
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B.
 The number of elements initialized in A and B are m and n respectively.
*/

 #include "myIncs.h"

 void merge(int A[], int m, int B[], int n)
 {
 	int a = m - 1, b = n - 1;
 	int c = m + n - 1;
 	while(a >= 0 && b >= 0)
 	{
 		if (A[a] < B[b])
 		{
 			A[c--] = B[b--];
 		}
 		else
 		{
 			A[c--] = A[a--];
 		}
 	}
 	while(a >= 0)
 	{
 		A[c--] = A[a--];
 	}
 	while(b >= 0)
 	{
 		A[c--] = B[b--];
 	}
 }

 int main(int argc, char const *argv[])
 {
 	int A[] = {1,2,3,4,5,6,231,0,0,00,0,00,0,00,0,00,0,00,0,00,0,00,0,00,0,0};
 	int m = 7;
 	int B[] = {2,5,6,7,8,9,22,131};
 	int n = 8;

 	for (int i = 0; i < m; ++i)
 	{
 		cout<<A[i]<<", ";
 	}
 	cout<<endl;
 	for (int i = 0; i < n; ++i)
 	{
 		cout<<B[i]<<", ";
 	}
 	cout<<endl;


 	merge(A, m, B , n);


 	 for (int i = 0; i < m+n; ++i)
 	{
 		cout<<A[i]<<", ";
 	}
 	cout<<endl;
 	return 0;
 }