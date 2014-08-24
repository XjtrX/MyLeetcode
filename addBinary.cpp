/*
author: jtr@BNU
date: 14.8.24
peoblem:
Add Binary Total Accepted: 15108 Total Submissions: 58467 My Submissions
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b)
{
	int lena = a.size();
	int lenb = b.size();
	int maxab = max(lenb, lena);
	string res(maxab, '0');
	int up = 0;
	while(lena && lenb && maxab)
	{
		lena--; lenb--; maxab--;
		int tem = a[lena] - '0' + b[lenb] - '0' + up;
		up = tem/2;
		tem = tem%2;
		res[maxab] = tem + '0';
	}
	while(lena && maxab)
	{
		lena--; maxab--;
		int tem = a[lena] - '0' + up;
		up = tem/2;
		tem = tem%2;
		res[maxab] = tem + '0';	
	}
	while(lenb && maxab)
	{
		lenb--; maxab--;
		int tem = b[lenb] - '0' + up;
		up = tem/2;
		tem = tem%2;
		res[maxab] = tem + '0';	
	}
	if (up)
	{
		res.insert(res.begin(), '0' + up);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	string a = "10101010100101";
	string b = "100100";
	
	cout<<a<<endl<<b<<endl;
	cout<<addBinary(a, a)<<endl;
	return 0;
}