/*
author: jtr@BNU
date:14.8.13
problem:

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

// I -> 1
// V -> 5
// X -> 10
// L -> 50
// C -> 100
// D -> 500
// M -> 1000

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int romanToInt(string s){
	int res = 0;
	int len = s.size() - 1;

	while(len >= 0){
		switch(s[len])
		{
			case 'I':
				res += 1;
				--len;
				break;
			case 'V':
				res += 5;
				while((--len) >= 0 && s[len] == 'I') res -= 1;
				break;
			case 'X':
				res += 10;
				while((--len) >= 0 && s[len] == 'I') res -= 1;
				break;
			case 'L':
				res += 50;
				while((--len) >= 0 && s[len] == 'X') res -= 10;
				break;
			case 'C':
				res += 100;
				while((--len) >= 0 && s[len] == 'X') res -= 10;
				break;
			case 'D':
				res += 500;
				while((--len) >= 0 && s[len] == 'C') res -= 100;
				break;
			case 'M':
				res += 1000;
				while((--len) >= 0 && s[len] == 'C') res -= 100;
				break;
		}
	}
	return res;
}

int main()
{
	string s = "MMIV";

	cout<<s<<" = "<<romanToInt(s)<<endl;
	return 0;
}