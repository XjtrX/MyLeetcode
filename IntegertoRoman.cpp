/*
author: jtr@BNU
date: 14.8.13
problem:
Integer to Roman Total Accepted: 12215 Total Submissions: 36642 My Submissions
Given an integer, convert it to a roman numeral.

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
#include <vector>
#include <map>
#include <string>
using namespace std;

string intToRoman(int num) {
	string res;
	if (num <= 0 || num > 3999)
	{
		return res;
	}
	int tem = num;
	int len = 0;
	while(tem != 0 ){
		int cur = tem % 10;
		tem /= 10;
		len++;
		string s;
		switch(len)
		{
			case 1:
				s.clear();
				if (cur == 9)
				{
					s = "IX";
				}
				else if (cur > 5)
				{
					s = "V";
					while(cur != 5)
					{
						s.append("I");
						cur--;
					}
				}
				else if(cur == 5)
				{
					s = "V";
				}
				else if (cur == 4)
				{
					s = "IV";
				}
				else if (cur > 0)
				{
					while(cur != 0)
					{
						s.append("I");
						cur--;
					}
				}
				break;
			case 2:
				s.clear();
				if (cur == 9)
				{
					s = "XC";
				}
				else if (cur > 5)
				{
					s = "L";
					while(cur != 5)
					{
						s.append("X");
						cur--;
					}
				}
				else if(cur == 5)
				{
					s = "L";
				}
				else if (cur == 4)
				{
					s = "XL";
				}
				else if (cur > 0)
				{
					while(cur != 0)
					{	cur--;
						s.append("X");
					}
				}
				break;
			case 3:
				s.clear();
				if (cur == 9)
				{
					s = "CM";
				}
				else if (cur > 5)
				{
					s = "D";
					while(cur != 5)
					{
						s.append("C");
						cur--;
					}
				}
				else if(cur == 5)
				{
					s = "D";
				}
				else if (cur == 4)
				{
					s = "CD";
				}
				else if (cur > 0)
				{
					while(cur != 0)
					{
						s.append("C");
						cur--;
					}
				}
				break;
			case 4:
				s.clear();
				if (cur > 0 && cur < 5)
				{
					while(cur != 0)
					{
						cur--;
						s.append("M");
					}
				}
				break;
		}
		res = s.append(res);
	}
	return res;
}

int main()
{
	int num = 90;
	cout<< num << " = "<< intToRoman(num) << endl;
	return 0;
}
