/*
author: jtr@BNU
date: 14.8.21
problem:
Multiply Strings Total Accepted: 11648 Total Submissions: 56768 My Submissions
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

//the numbers are non-negative.
string strAddStr(string num1, string num2)
{
	if (num1.size() < 1)
	{
		return num2;
	}
	if (num1 == "0" || num2 == "0")
	{
		return (num1 == "0") ? num2 : num1;
	}
	size_t n1 = num1.size() - 1, n2 = num2.size() - 1;
	size_t m = max(n1, n2);
	string res = (n1 > n2) ? num1 : num2;
	int up = 0;
	while(m >= 0 && n1 >= 0 && n2 >= 0)
	{
		// cout<<"m, n1, n2 = "<<m<<", "<<n1<<","<<n2<<endl;
		int tem = (num1[n1] - '0') + (num2[n2] - '0') + up;
		// cout<<"tem = "<<tem<<endl;
		up = tem / 10;
		tem = tem % 10;
		//cout<<"up , tem "<< up << " , "<< tem<<endl;
		res[m] = tem + '0';
		//cout<<res<<endl;
		if (n1 == 0 || n2 == 0 || m == 0)
		{
			m--;
			n1--;n2--;
			break;
		}
		m--;
		n1--;n2--;
	}
	// cout<<"m, up "<< m <<", "<<up<<endl;
	while( m < max(num1.size(),num2.size()) && m >= 0 && up == 1)
	{
		int tem = res[m] - '0' + up;
		up = tem/10;
		tem = tem % 10;
		res[m] = tem + '0';
		if (m == 0)
		{
			break;
		}
		m--;
	}
	if (up == 1)
	{
		res.insert(res.begin(),'1');
	}
	return res;
}
string charXStr(char c, string s)
{
	if (c == '0' )
	{
		return "0";
	}
	string res = s;
	size_t len = s.size();
	int mu = c - '0';
	int up = 0;
	while(len)
	{
		--len;
		int tem = (s[len] - '0') * mu + up;
		up = tem / 10;
		tem %= 10;
		res[len] = tem + '0';
	}
	
	if (up > 0)
	{
		res.insert(res.begin(), '0' + up);
	}
	if (res == string(res.size(),'0'))
	{
		return "0";
	}
	// cout<<res<<"  len :"<<len<<" up: "<< up <<endl;
	return res;
}
string multiply(string num1, string num2)
{
	size_t len1 = num1.size(), len2 = num2.size();
	if (len2 < 1 || len1 < 1)
	{
		return "";
	}
	// if (num1 == "0" || num2 == "0")
	// {
	// 	return "0";
	// }
	string res;
	for (size_t i = len1 - 1; ; --i)
	{
		string ap(len1 - i - 1,'0');
		string tem = num2 + ap;
		tem = charXStr(num1[i], tem);
		// cout<<"res = "<<res<<" + "<<tem<<endl;
		res = strAddStr(res,tem);
		if (i == 0)
		{
			break;
		}
	}

	return res;
}

int main(int argc, char const *argv[])
{
	string num1 = "9133";
	string num2 = "0";
	cout<<num2<<endl<<num1<<endl;
	cout<<multiply(num1, num2) <<" =? " << 100 * 9133 <<endl;
	return 0;
}