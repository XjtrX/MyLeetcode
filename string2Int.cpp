/*
author: jtr@BNU
date: 14.8.10
problem:
String to Integer (atoi) Total Accepted: 14399 Total Submissions: 98484 My Submissions
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/
#include <cstring>
#include <iostream>
using namespace std;

bool flag = true;
int stringtoi(const char *str) {
	int res = 0;
	if (str == NULL)
	{
		flag = false;
		return 0;
	}
	int len = strlen(str);
	int cur = 0;
	bool posit = true;
	while(str[cur] == ' ') cur++;
	switch(str[cur])
	{
		case '+':
			posit = true;
			cur++;
			break;
		case '-':
			posit = false;
			cur++;
			break;
		default:
			break;
	}
	while(cur<len && str[cur] >= '0' && str[cur] <= '9')
	{

		//if (res <= 0)
		//{
		//	cout<<"over followed"<<endl;
		//	flag = false;
		//	return 0;
		//}
		if (res > 0x7fffffff /10 ||
			 (res == 0x7fffffff/10 && (str[cur] - '0'> 0x7fffffff%10)))
		{
			if (posit)
			{
				return 0x7fffffff;
			}
			else
				return 0x80000000;
		}
		res = res * 10 + (str[cur] - '0');
		cur++;
	}

	if (!posit)
	{
		res = -1 * res;
		return res;
	}
	return res;
}

int main()
{
	char s []= "10522545459";
	cout<<s<<endl;
	cout<<stringtoi(s)<<endl;

	int a = 0x80000000;
	cout<<"--------------------------"<<endl<<a<<endl;
	return 0;
}