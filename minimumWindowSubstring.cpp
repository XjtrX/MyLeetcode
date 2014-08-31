/*
author: jtr@BNU
date: 14.8.30
problem:
Minimum Window Substring Total Accepted: 12530 Total Submissions: 69768 My Submissions
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

string minWindow(string S, string T)
{
	string res = "";
	int lens = S.size(), lent = T.size();
	map<char,int> mapT;
	for(int i = 0; i < lent; ++i)
	{
		mapT[T[i]]++;
	}
	map<char,int> mapA;
	mapA.clear();
	int minilen = lens + 1;
	int left = 0, wigth = 0, length = 0;
	for (int i = 0; i < lens; ++i)
	{
		if (mapT[S[i]] > 0)
		{
			mapA[S[i]]++;
			if (mapA[S[i]] <= mapT[S[i]])
			{
				length++;
			}
		}

		// cout<<S[left]<<", "<<length<<", "<<wigth << ", " <<i<<endl;
		wigth++;
		if (length == lent)
		{

			while(left <= i && (mapA[S[left]] > mapT[S[left]] || mapT[S[left]] == 0))
			{
				mapA[S[left]] = (mapT[S[left]] == 0) ? mapA[S[left]] : mapA[S[left]] - 1;
				left++;
				wigth--;

			}
			// if(left == lens - 1) return res;
			if (wigth < minilen)
			{
				res = S.substr(left, wigth);
				minilen = wigth;
			}
			length--;
			mapA[S[left]] = (mapT[S[left]] == 0) ? mapA[S[left]] : mapA[S[left]] - 1;
			left++;
			wigth--;
			while(left <= i && (mapA[S[left]] > mapT[S[left]] || mapT[S[left]] == 0))
			{
				mapA[S[left]] = (mapT[S[left]] == 0) ? mapA[S[left]] : mapA[S[left]] - 1;
				left++;
				wigth--;
			}
			// wigth++;


			// if(left == lens - 1) return res;
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	string S = "cabwefgewcwaefgcf";
	string T = "cae";

	cout<<S<<endl<<T<<endl<<endl<<minWindow(S,T)<<endl;
	return 0;
}
