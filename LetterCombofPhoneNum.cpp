/*
autor: jtr@BNU
date: 14.8.13
problem:
Letter Combinations of a Phone Number Total Accepted: 14164 Total Submissions: 54233 My Submissions
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

// 1 = {}
// 2 = {a,b,c}
// 3 = {d,e,f},  
// 4 = {g,h,i},  
// 5 = {j,k,l},  
// 6 = {m,n,o},  
// 7 = {p,q,r,t},
// 8 = {t,u,v},  
// 9 = {w,x,y,z},
// 0 = {_}

#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> phone[] = {{""},{},{"a","b","c"},{"d","e","f"},
 									{"g","h","i"}, {"j","k","l"},
 									{"m","n","o"},  {"p","q","r","t"},
 									{"t","u","v"},  {"w","x","y","z"}};
vector<string> letterCombinations(string digits){
	vector<string> res;
	res.clear();
	if (digits.size()< 1)
	{
		string s;
		res.push_back(s);
		return res;
	}
	if (digits.size() == 1)
	{
		size_t pos = digits[0] - '0';
		for (std::vector<string>::iterator i = (phone[pos]).begin(); i != (phone[pos]).end(); ++i)
		{
			res.push_back(*i);
		}
		return res;
	}
	string tem = digits.substr(1,digits.size());

	size_t po = digits[0] - '0';
	for (std::vector<string>::iterator i = phone[po].begin(); i != phone[po].end(); ++i)
	{
		std::vector<string> v = letterCombinations(tem);
		for (std::vector<string>::iterator itr = v.begin(); itr != v.end(); ++itr)
		{
			string tem = *i;
			string s = tem.append(*itr);
			res.push_back(s);
		}
	}
	return res;
}
int main()
{
	string digits = "23";

	cout<<digits<<endl;
	std::vector<string> v = letterCombinations(digits);

	for (std::vector<string>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout<<*i<<endl;
	}
	return 0;
}