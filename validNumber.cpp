/*
author: jtr@BNU
date: 14.8.24
problem:
Valid Number Total Accepted: 9855 Total Submissions: 89851 My Submissions
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;
// //give up this way..........
// bool isNumber(const char *s)
// {
// 	bool res = false;
// 	map<char,bool> symbol = {
// 		make_pair('.',false),
// 		make_pair('e',false),
// 		make_pair('E',false),
// 		make_pair('+',false),
// 		make_pair('-',false),
// 		make_pair(' ',false)
// 	};
// 	bool hasnum = false;
// 	bool space  = false;
// 	const char * cur = s;
// 	while(*cur == ' ') 
// 	{
// 		cur++;
// 		space = true;
// 	}
// 	if (*cur == '\0')
// 	{
// 		return false;
// 	}
// 	symbol[' '] = true;
// 	while(*cur != '\0')
// 	{
// 		if (*cur >= '0' && *cur <= '9')
// 		{
// 			hasnum = true;
// 			cur++;
// 			continue;
// 		}
// 		switch(*cur)
// 		{
// 			case '.':
// 				if (symbol['.'])
// 				{
// 					return false;
// 				}
// 				else
// 				{
// 					if (hasnum && (symbol['e'] || symbol['E']))
// 					{
// 						return false;
// 					}
// 					if ((*(cur + 1) == '\0')&&((*(cur - 1) == ' ')||*(cur - 1) == '+' || *(cur - 1) == '-' || *(cur - 1) == 'e' || *(cur - 1) == 'E' || !hasnum))
// 					{
// 						return false;
// 					}
// 					symbol['.'] = true;
// 				}
// 				break;
// 			case '+':
// 				if (symbol['+'])
// 				{
// 					return false;
// 				}
// 				else
// 				{
// 					if (hasnum && (!symbol['e'] || !symbol['E']))
// 					{
// 						return false;
// 					}
// 					if (!(*(cur - 1) == 'e' || *(cur - 1) == 'E') )
// 					{
// 						return false;
// 					}
// 					if(*(cur + 1) == '\0' || *(cur + 1) == 'e' || *(cur + 1) == 'E'||*(cur + 1) == '+' ||*(cur + 1) == '-')
// 						return false;
// 					symbol['+'] = true;
// 				}
// 				break;
// 			case '-':
// 				if (symbol['-'])
// 				{
// 					return false;
// 				}
// 				else
// 				{
// 					if (hasnum && (symbol['e'] || symbol['E']))
// 					{
// 						return false;
// 					}
// 					// if (!(*(cur - 1) == 'e' || *(cur - 1) == 'E') )
// 					// {
// 					// 	return false;
// 					// }
// 					if (*(cur + 1) == '\0' || *(cur + 1) == 'e' || *(cur + 1) == 'E'||*(cur + 1) == '+' ||*(cur + 1) == '-')
// 					{
// 						return false;
// 					}
// 					symbol['-'] = true;
// 				}
// 				break;
// 			case 'e':
// 			case 'E':
// 				if (symbol['E'] || symbol['e'])
// 				{
// 					return false;
// 				}
// 				else
// 				{
// 					if (!hasnum)
// 					{
// 						return false;
// 					}
// 					if(*(cur + 1) == '\0' || cur == s || *(cur + 1) == 'e' || *(cur + 1) == 'E' || *(cur + 1) == ' ')
// 						return false;
// 					symbol['E'] = true;
// 					symbol['e'] = true;
// 					symbol['+'] = false;
// 					symbol['-'] = false;
// 					symbol['.'] = true;
// 				}
// 				break;
// 			default:
// 				// if ((*(cur-1) == '+' || *(cur-1) == '-' || *(cur-1) == 'e' || *(cur-1) == 'E') && !hasnum )
// 				// {
// 				// 	return false;
// 				// }
// 				while(*cur == ' ') cur++;
// 				if (*cur == '\0' && hasnum)
// 				{
// 					return true;
// 				}
// 				return false;
// 				break;
// 		}
// 		cur++;
// 	}
// 	return true;
// }

bool isNumber(const char * s)
{
	enum symbol
	{
		START = 0, //start
		PLUS,
		MINUS,
		E,
		NUM,
		DOT,
		SPACE
	};
	int statements[][7] = {
		-1,1,1,-1,3,2,0,//start
		-1,-1,-1,-1,3,2,-1, //1
		-1,-1,-1,-1,4,-1,-1, //2
		-1,-1,-1,5,3,4,8,//3
		-1,-1,-1,5,4,-1,8,//4
		-1,6,6,-1,7,-1,-1,//5
		-1,-1,-1,-1,7,-1,-1,//6
		-1,-1,-1,-1,7,-1,8,//7
		-1,-1,-1,-1,-1,-1,8
	};
	int flag = 0;
	while(*s != '\0')
	{
		switch(*s)
		{
			case '+':
				flag = statements[flag][PLUS];
				break;
			case '-':
				flag = statements[flag][MINUS];
				break;
			case 'e':
			case 'E':
				flag = statements[flag][E];
				break;
			case '.':
				flag = statements[flag][DOT];
				break;
			case ' ':
				flag = statements[flag][SPACE];
				break;
			case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
				flag = statements[flag][NUM];
				break;
			default:
				return false;
				break;
		}
		cout<<*s<<"->"<<flag<<endl;
		if (flag == -1)
		{
			return false;
		}
		s++;
	}
	if (flag == 3 || flag == 4 || flag == 7 || flag == 8)
	{
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	char s[] = "1 ";
	cout<<s<<( isNumber(s) ? (" is a number.") : (" is not a number."))<<endl;
	return 0;
}
