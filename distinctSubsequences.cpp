/*
author: jtr@BNU
date: 14.9.3
problem:
Distinct Subsequences Total Accepted: 14462 Total Submissions: 58417 My Submissions
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) 
of the characters without disturbing the relative positions of the remaining characters. 
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
#include "myIncs.h"

int numDistinct(string S, string T)
{
	if(S == T) return 1;
	int lens = S.size(), lent = T.size();
	if(lens < lent) return 0;

	vector<int> M(lent + 1, 0);

	for (int i = 0; i < lens; ++i)
	{
		M[0] = 1;
		for (int j = (lent > i + 1 ? i + 1 : lent); j > 0 ; --j)
		{
			M[j] = M[j] + (S[i] == T[j - 1] ? M[j - 1] : 0);
		}
	}
	return M[lent];
}

int main(int argc, char const *argv[])
{
	string S = "avsfddddda";
	string T = "avsfda";

	cout<<S<<endl<<T<<endl<<numDistinct(S,T)<<endl;
	return 0;
}