/*
author: jtr@BNU
date: 14.8.25
problem:
Text Justification Total Accepted: 7766 Total Submissions: 55527 My Submissions
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

vector<string> fullJustify(vector<string> &words, int L)
{

	vector<string> res;
	if ((words[0]) == "" && words.size() == 1)
	{
		string s(L,' ');
		res.push_back(s);
		return res;
	}
	int tem = 0;
	int nSpace = 0;
	vector<int> pos;
	string str;
	for (std::vector<string>::iterator itr = words.begin(); itr != words.end(); ++itr)
	{
		int len = itr->size();
		if(len > L) return res;
		if (tem == 0)
		{
			str.clear();
			str.append(*itr);
			if (len < L)
			{
				str.append(" ");
				nSpace++;
			}
			tem = len + nSpace;
			pos.push_back(tem);
		}
		else
		{
			if (tem + len < L)
			{
				str.append(*itr);
				str.append(" ");
				tem = tem + len + 1;
				nSpace++;
				pos.push_back(tem);
				// if (tem == L)
				// {
				// 	str.insert(pos[0],1,' ');
				// 	str.erase(str.end()--);
				// 	res.push_back(str);
				// 	tem = 0;
				// 	nSpace = 0;
				// 	pos.clear();
				// 	str.clear();
				// 	continue;
				// }
			}
			else if (tem + len == L)
			{
				str.append(*itr);
				res.push_back(str);
				str.clear();
				pos.clear();
				tem = 0;
				nSpace = 0;
			}
			else
			{
				
				int restSpace = (L-tem);
				if (str.back() == ' ' && nSpace > 1)
				{
					str.pop_back();
					pos.pop_back();
					restSpace++;
				}
				int moreSpace = (nSpace > 1) ? restSpace % (nSpace - 1) : restSpace % (nSpace );
				int intsertSpace = (nSpace > 1) ? (restSpace - moreSpace)/(nSpace - 1) : (restSpace - moreSpace)/(nSpace);
				moreSpace = pos.size() - moreSpace;
				for (std::vector<int>::reverse_iterator i = pos.rbegin(); i != pos.rend(); ++i)
				{
					((moreSpace--) <= 0) ? str.insert(*i, intsertSpace + 1, ' ' ) : str.insert(*i, intsertSpace, ' ' );
				}
				res.push_back(str);
				str.clear();
				tem = 0;
				nSpace = 0;
				pos.clear();
				--itr;
			}
		}

		if (tem == L)
		{
			if (str.back() == ' ' && nSpace > 1)
			{
				str.pop_back();
				str.insert(pos[0],1,' ');
			}
			tem = 0;
			nSpace = 0;
			pos.clear();
			res.push_back(str);
			str.clear();
			continue;
		}
	}
	if(str.size() != 0)
	{
		str.append(string(L-tem,' '));
		res.push_back(str);
	}

	return res;
}

int main(int argc, char const *argv[])
{
	vector<string> words = {
		"Imagination","is","more","important","than","knowledge."
	};
	int L = 14;


	for (std::vector<string>::iterator itr = words.begin(); itr != words.end(); ++itr)
	{
		cout<<*itr<<" ";
	}
	cout<<endl<<"-------"<<endl;

	vector<string> res = fullJustify(words, L);

	for (std::vector<string>::iterator i = res.begin(); i != res.end(); ++i)
	{
		cout<<*i<<endl;
	}
	cout<<endl;
	return 0;
}