/*
author: jtr@BNU
date: 14.8.25
problem:
Plus One Total Accepted: 17268 Total Submissions: 54833 My Submissions
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> plusOne(vector<int> & digits)
{
	std::vector<int> res = digits;
	int len = digits.size();
	int up = 0;
	int tem;
	while(len)
	{
		len--;
		tem = (len == digits.size() - 1) ? up + digits[len] + 1 : up + digits[len];
		up = tem/10;
		tem = tem%10;
		res[len] = tem;
	}
	if (up)
	{
		res.insert(res.begin(),up);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<int> digits = {};
	for (std::vector<int >::iterator itr = digits.begin(); itr != digits.end(); ++itr)
	{
		cout<<*itr;
	}
	cout<<endl;


	std::vector<int > res = plusOne(digits);
	for (std::vector<int >::iterator i = res.begin(); i != res.end(); ++i)
	{
		cout<<*i;
	}
	cout<<endl;
	return 0;
}