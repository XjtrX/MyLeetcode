/*
author: jtr@BNU
date: 14.9.3
problem:
Gray Code Total Accepted: 15226 Total Submissions: 47486 My Submissions
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

#include "myIncs.h"



vector<int> grayCode(int n)
{
	vector<int> res;
	if (n < 1) 
	{
		res.push_back(0);
		return res;
	}
	if (n == 1)
	{
		res.push_back(0);
		res.push_back(1);
		return res;
	}
	vector<int> tem = grayCode(n - 1);
	res = tem;
	for (std::vector<int>::reverse_iterator i = tem.rbegin(); i != tem.rend(); ++i)
	{
		int t = 1<<n-1;
		t += (*i);
		res.push_back(t);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n = 6;
	vector<int> res = grayCode(n);
	cout<<"------n-----"<<endl;
	for (std::vector<int>::iterator i = res.begin(); i != res.end(); ++i)
	{
		cout<<*i<<endl;
	}
	cout<<endl;
	return 0;
}