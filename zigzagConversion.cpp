/*
autor: jtr@BNU
date: 14.8.10
problem:
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int nRows) {
	string res;
	if (nRows<2 || nRows >= s.size())
	{
		return s;
	}
	res.resize(s.size());
	int k = 0;
	for (int i = 1; i <= nRows; ++i)
	{
		int start = i - 1;
		res[k] = s[start];
		k++;
		while(start < s.size())
		{
			int step = nRows - i;
			start += 2*step;
			if(step != 0 && start < s.size())
				res[k++] = s[start];
			step = i - 1;
			start += 2*step;
			if (step != 0 && start <s.size())
			{
				res[k++] = s[start];
			}
		}
	}
	return res;
}

int main()
{
	string s = "abcdefghijklmnopqrstuvwxyz";

	cout<<s<<endl<<endl;
	for (int i = 1; i < 6; ++i)
	{
		cout<<"---------"<<i<<"--------"<<endl;
		cout<<convert(s, i)<<endl;
	}
	
	return 0;
}