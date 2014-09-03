/*
autho: jtr@BNU
date: 14.9.3
peoblem:
Interleaving String Total Accepted: 14009 Total Submissions: 72917 My Submissions
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

#include "myIncs.h"


bool isInterleave(string s1, string s2, string s3)
{
	int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
	if(len1 + len2 != len3) return false;
	if(len1 == 0) return s2 == s3;
	if(len2 == 0) return s1 == s3;
	vector<vector<bool> > M(len1 + 1, vector<bool>(len2 + 1, false));
	for (int i = 1; i <= len1; ++i)
	{
		M[i][0] = s1.substr(0,i) == s3.substr(0,i);
		if (!M[i][0]) break;
	}
	for (int i = 1; i <= len2; ++i)
	{
		M[0][i] = s2.substr(0,i) == s3.substr(0,i);
		if(!M[0][i]) break;
	}

	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			M[i][j] = ((M[i - 1][j] &&  s1[i - 1] == s3[i + j - 1] ) || (M[i][j - 1] && s2[j - 1] == s3[i + j - 1])) ;
		}
	}
	return M[len1][len2];
}


int main(int argc, char const *argv[])
{
	string s1 = "ab";
	string s2 = "bc";
	string s3 = "bcab";

	cout<<s3<<(isInterleave(s1, s2, s3) ? " is ": " is not ")<<"formed by the interleaving of "<<s1<<" and "<<s2<<"."<<endl;
	return 0;
}