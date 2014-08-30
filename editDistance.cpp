/*
author: jtr@BNU
date: 14.8.25
peoblem:
Edit Distance Total Accepted: 13327 Total Submissions: 52758 My Submissions
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;



int minDistance(string word1, string word2)
{
	int len1 = word1.size(), len2 = word2.size();
	if (len1 == 0 || len2 == 0)
	{
		return (len1 == 0) ? len2 : len1;
	}
	vector<int> curDis(len1 + 1, 0);
	int pre = 0, res = 0;
	for (int i = 0; i <= len1; ++i)
	{
		curDis[i] = i;
	}

	for (int i = 0; i <= len2; ++i)
	{
		pre = curDis[0];
		curDis[0] = i;
		for (int j = 1; j <= len1; ++j)
		{
			if (word1[j-1] == word2[ i - 1 ])
			{
				res = pre;
				pre = curDis[j];
				curDis[j] = res;
			}
			else
			{
				res = min(curDis[ j - 1] + 1,curDis[j] + 1);
				res = min(pre + 1, res);
				pre = curDis[j];
				curDis[j] = res;
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	string word1 = "";
	string word2 = "absssssss";

	cout<<word1<<endl<<word2<<endl;
	cout<<minDistance(word1,word2)<<endl;
	return 0;
}