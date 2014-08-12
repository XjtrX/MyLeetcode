#include <iostream>
using namespace std;
/*
author: jtr@BNU
date:2014. 8.8
Median of Two Sorted Arrays Total Accepted: 16839 Total Submissions: 97816 My Submissions
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

*/
double findKth(int A[], int m, int   B[], int n, int k)
{
	if (m>n)
	{
		return findKth(B,n,A,m,k);
	}
	if (m == 0)
	{
		return  B[k-1] ;
	}
	if (k == 1)
	{
		return min(A[0],B[0]);
	}

	int mid = k>>1;
	int mida = min(mid, m );
	int midb = k - mida;
	if (A[mida -1] == B[midb - 1])
	{
		return A[mida - 1];
	}
	else if (A[mida - 1] < B[midb - 1])
	{
		return findKth(A+mida , m - mida , B, n , k - mida );
	}
	else
	{
		return findKth(A,m, B+midb , n - midb, k - midb );
	}

}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
	int k = (m + n)>>1;
	if (m<0||n<0 )
	{
		return 0.0;//ambious
	}

	if ((m+n)&0x1)
	{
		return findKth(A,m,B,n,k+1);
	}
	else
	{
		return (findKth(A,m,B,n,k)+findKth(A,m,B,n,k+1))*0.5;
	}
}


int main()
{
	int A[] ={1}; //{2,4,5,7,9,12,534,546,788,999,3432};
	int m =1;//1;
	int B[] = {2,3,4,5,555};//{-199,-23,-1,13,23,42,5211,54566};
	int n = 5;//9;
	cout<<"A: ";
	for (int i = 0; i < m; ++i)
	{
		cout<<A[i]<<",";
	}
	cout<<endl<<"B: ";
	for (int i = 0; i < n; ++i)
	{
		cout<<B[i]<<",";
	}
	cout<<endl;
	cout<<findMedianSortedArrays(A,m,B,n)<<endl;
}