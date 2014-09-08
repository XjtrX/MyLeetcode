/*
author: jtr@BNU
date: 14.9.7
problem:
Palindrome Partitioning II Total Accepted: 14669 Total Submissions: 81354 My Submissions
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

#include "myIncs.h"

int minCut(string s)
{
	int len = s.size();
	if(len < 2) return 0;
	vector<int> res(len + 1, len);
	res[len] = -1;
	vector<vector<bool> > isPal(len, vector<bool> ( len , false));

	for (int i = len - 1; i >= 0; --i)
	{
		for (int j = i; j < len ; ++j)
		{
			if(s[i] == s[j] && (i == j || i + 1 == j || isPal[i + 1][j - 1]))
			{
				isPal[i][j] = true;
				res[i] = min(res[i], res[j + 1] + 1);
			}
			// cout<<i<<", "<<j<<", "<<res[i]<<", "<<res[j + 1]<<endl;
		}
		
	}
	return res[0];
}

int main(int argc, char const *argv[])
{
	string s = "bb";

	cout<<s<<endl;
	cout<<minCut(s)<<endl;
	return 0;
}
