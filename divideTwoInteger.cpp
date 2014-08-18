/*
author: jtr@BNU
date: 14.8.18
problem:
Divide Two Integers Total Accepted: 14752 Total Submissions: 90566 My Submissions
Divide two integers without using multiplication, division and mod operator.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int divide(int dividend, int divisor)
{
	long long res = 0;
	int flag = ((dividend & 0x80000000) ^ (divisor & 0x80000000)) ? -1 : 1;
	if (divisor == 0)
	{
		if (dividend == 0)
		{
			return 0;
		}
		return (dividend>0) ? 0x7fffffff : 0x80000000;
	}

	long long ddividend = (dividend & 0x80000000) ? -(long long )dividend : dividend;
	long long ddivisor = (divisor & 0x80000000) ? -(long long )divisor : divisor;
	if (ddividend < ddivisor)
	{
		return 0;
	}
	while(ddividend > ddivisor)
	{
		int tem = 0;
		long long  di = ddivisor;
		while(ddividend > di)
		{
			ddividend -= di;
			res += (1<<tem);
			di = di<<1;
			tem++;
		}
	}
	if (ddividend == ddivisor)
	{
		res++;
	}
	return (flag > 0) ? res : -res;

}

int main(int argc, char const *argv[])
{
	int dividend = 4;
	int divisor = 2;
	cout<<dividend<<"/"<<divisor<<" = "<<divide(dividend, divisor)<<" =? "<<dividend/divisor<<endl;
	return 0;
}