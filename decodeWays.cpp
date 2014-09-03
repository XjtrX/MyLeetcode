/*
author: jtr@BNU
date: 14.9.3
problem:
Decode Ways Total Accepted: 14892 Total Submissions: 92847 My Submissions
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

#include "myIncs.h"

int numDecodings(string s)
{
	int len = s.size();
	if(s == "") return 0;
	if(s[0] == '0') return 0;
	if(len == 1) return 1;
	vector<int> res(len, 0);

	res[0] = (s[len - 1] == '0') ? 0 : 1;
	if (s[len - 2] == '1' || ((s[len - 2] == '2' && (s[len - 1] - '0' < 7))))
	{
		if (s[len - 1] != '0')
		{
			res[1] = 2;
		}
		else
			res[1] = 1;
	}
	else if (s[len - 1] != '0' && s[len - 2] != '0')
	{
		res[1] = 1;
	}
	// cout<<res[0]<<", "<<res[1]<<endl;

	for (int i = 2; i < len; ++i)
	{
		res[i] += (s[len - 1 - i] == '0') ? 0 : res[i - 1];
		if (s[len - 1 - i] == '1' || ((s[len - 1 - i] == '2') && (s[len - i] - '0' < 7)))
		{
			res[i] += res[i - 2];
		}
		// if(res[i] == 0) return 0;
	}
	return max(res[len - 1],res[len - 2]);
}

int main(int argc, char const *argv[])
{
	string s = "1010";

	cout<<s<<endl<<endl;
	cout<<numDecodings(s)<<endl;
	return 0;
}